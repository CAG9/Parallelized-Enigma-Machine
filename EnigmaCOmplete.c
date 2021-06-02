#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROTATE 26

const char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *rotor_ciphers[] = {
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
    "VZBRGITYUPSDNHLXAWMJQOFECK",
    "JPGVOUMFYQBENHZRDKASXLICTW",
    "NZJHGRCXMYSWBOUFAIVLPEKQDT",
    "FKQHTLXOCBJSPDZRAMEWNIUYGV"
};

const char *rotor_notches[] = {"Q", "E", "V", "J", "Z", "ZM", "ZM", "ZM"};

const char *rotor_turnovers[] = {"R", "F", "W", "K", "A", "AN", "AN", "AN"};

const char *reflectors[] = {
    "EJMZALYXVBWFCRQUONTSPIKHGD",
    "YRUHQSLDPXNGOKMIEBFZCWVJAT",
    "FVPJIAOYEDRZXWGCTKUQSBNMHL"
};

struct Rotor {
    int             offset;
    int             turnnext;
    const char      *cipher;
    const char      *turnover;
    const char      *notch;
};

struct Enigma {
    int             numrotors;
    const char      *reflector;
    struct Rotor    rotors[8];
};

/*
 * Produce a rotor object
 * Setup the correct offset, cipher set and turn overs.
 */
struct Rotor new_rotor(struct Enigma *machine, int rotornumber, int offset) {
    struct Rotor r;
    r.offset = offset;
    r.turnnext = 0;
    r.cipher = rotor_ciphers[rotornumber - 1];
    r.turnover = rotor_turnovers[rotornumber - 1];
    r.notch = rotor_notches[rotornumber - 1];
    machine->numrotors++;

    return r;
}

/*
 * Return the index position of a character inside a string
 * if not found then -1
 **/
int str_index(const char *str, int character) {
    char *pos;
    int index;
    pos = strchr(str, character);

    // pointer arithmetic
    if (pos){
        index = (int) (pos - str);
    } else {
        index = -1;
    }

    return index;
}

/*
 * Cycle a rotor's offset but keep it in the array.
 */
void rotor_cycle(struct Rotor *rotor) {
    rotor->offset++;
    rotor->offset = rotor->offset % ROTATE;

    // Check if the notch is active, if so trigger the turnnext
    if(str_index(rotor->turnover, alpha[rotor->offset]) >= 0) {
        rotor->turnnext = 1;
    }
}

/*
 * Pass through a rotor, right to left, cipher to alpha.
 * returns the exit index location.
 */
int rotor_forward(struct Rotor *rotor, int index) {

    // In the cipher side, out the alpha side
    index = (index + rotor->offset) % ROTATE;
    index = str_index(alpha, rotor->cipher[index]);
    index = (ROTATE + index - rotor->offset) % ROTATE;

    return index;
}

/*
 * Pass through a rotor, left to right, alpha to cipher.
 * returns the exit index location.
 */
int rotor_reverse(struct Rotor *rotor, int index) {

    // In the cipher side, out the alpha side
    index = (index + rotor->offset) % ROTATE;
    index = str_index(rotor->cipher, alpha[index]);
    index = (ROTATE + index - rotor->offset) % ROTATE;

    return index;

}

/*
 * Run the enigma machine
 **/
int main(int argc, char *argv[])
{
    struct Enigma machine = {}; // initialized to defaults
    int i, character, index;

    // Command line options
    int opt_debug = 0;
    int opt_r1 = 3;
    int opt_r2 = 2;
    int opt_r3 = 1;
    int opt_o1 = 0;
    int opt_o2 = 0;
    int opt_o3 = 0;

    // Command Parsing
    for (i = 1; i < argc; i++){
        if (strcmp(argv[i], "-d") == 0) opt_debug = 1;
        if (strcmp(argv[i], "-r") == 0) {
            opt_r1 = atoi(&argv[i+1][0])/100;
            opt_r2 = atoi(&argv[i+1][1])/10;
            opt_r3 = atoi(&argv[i+1][2]);
            i++;
        }
        if (strcmp(argv[i], "-o") == 0) {
            opt_o1 = atoi(&argv[i+1][0])/100;
            opt_o2 = atoi(&argv[i+1][1])/10;
            opt_o3 = atoi(&argv[i+1][2]);
            i++;
        }
    }

    if(opt_debug) {
        printf("Rotors set to : %d %d %d \n", opt_r3, opt_r2, opt_r1);
        printf("Offsets set to: %d %d %d \n", opt_o3, opt_o2, opt_o1);
    }

    // Configure an enigma machine
    machine.reflector = reflectors[1];
    machine.rotors[0] = new_rotor(&machine, opt_r1, opt_o1);
    machine.rotors[1] = new_rotor(&machine, opt_r2, opt_o2);
    machine.rotors[2] = new_rotor(&machine, opt_r3, opt_o3);

    while((character = getchar())!=EOF) {

        if (!isalpha(character)) {
            printf("%c", character);
            continue;
        }

                character = toupper(character);

        // Plugboard
        index = str_index(alpha, character);
        if(opt_debug) {
            printf("Input character ******** %c \n", character);
        }

        // Cycle first rotor before pushing through,
        rotor_cycle(&machine.rotors[0]);

        // Double step the rotor
        if(str_index(machine.rotors[1].notch,
                    alpha[machine.rotors[1].offset]) >= 0 ) {
            rotor_cycle(&machine.rotors[1]);
        }

        // Stepping the rotors
        for(i=0; i < machine.numrotors - 1; i++) {
            character = alpha[machine.rotors[i].offset];

            if(machine.rotors[i].turnnext) {
                machine.rotors[i].turnnext = 0;
                rotor_cycle(&machine.rotors[i+1]);
                if(opt_debug) {
                    printf("Cycling  rotor :%d \n", i+1);
                    printf("Turnover rotor :%d \n", i);
                    printf("Character  is  :%c \n", character);
                }
            }
         }

        // Pass through all the rotors forward
        for(i=0; i < machine.numrotors; i++) {
            index = rotor_forward(&machine.rotors[i], index);
        }

        // Pass through the reflector
        if(opt_debug) {
            printf("Into reflector %c\n", alpha[index]);
            printf("Out of reflector %c\n", machine.reflector[index]);
        }

        // Inbound
        character = machine.reflector[index];
        // Outbound
        index = str_index(alpha, character);

        if(opt_debug) {
            printf("Index out of reflector %i\n", index);
            printf("->Reflected character %c \n", character);
        }

        // Pass back through the rotors in reverse
        for(i = machine.numrotors - 1; i >= 0; i--) {
            index = rotor_reverse(&machine.rotors[i], index);
        }

        // Pass through Plugboard
        character = alpha[index];

        if(opt_debug) {
           printf("Plugboard index %d \n", index);
           printf("Output character ******** ");
        }
        putchar(character);

        if(opt_debug) printf("\n\n");
    }

    return 0;
}

