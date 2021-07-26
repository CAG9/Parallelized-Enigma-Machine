/*
License GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
Contact:
    César Arcos González: cesar99ag@comunidad.unam.mx 
    Brian Kalid García Olivo: briankalid@comunidad.unam.mx
    José Vidal Cardona Rosas: ladivcr@comunidad.unam.mx
*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// define rotate
/*
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

const char *rotor_ciphers_spin[] = {
    'UWYGADFPVZBECKMTHXSLRINQOJ',
    'AJPCZWRLFBDKOTYUQGENHXMIVS',
    'TAGBPCSDQEUFVNZHYIXJWLRKOM',
    'HZWVARTNLGUPXQCEJMBSKDYOIF',
    'QCYLXWENFTZOSMVJUDKGIARPHB',
    'SKXQLHCNWARVGMEBJPTYFDZUIO',
    'QMGYVPEDRCWTIANUXFKZOSLHJB',
    'QJINSAYDVKBFRUHMCPLEWZTGXO'
};

const char *reflectors[] = {
    "EJMZALYXVBWFCRQUONTSPIKHGD",
    "YRUHQSLDPXNGOKMIEBFZCWVJAT",
    "FVPJIAOYEDRZXWGCTKUQSBNMHL"
};
*/


char* replaceWord(const char* s, const char* oldW,const char* newW);
void normalized_text(char text[],char alphabet[],char newstring[]);
void upper(char str[]);
int char_to_pos(char txt[],char alphabet[]);
char change(char character[],char charset[],int n);
int ordc(char character[]);







int main()
{
    char str[] = "xxforxx xx for xx";
    char c[] = "A";
    char newstring[250];
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* result = NULL;
    int n = 0;
    normalized_text(str,alphabet,newstring);
    printf("Definitive %s\n",newstring);
    int pos = char_to_pos(c,alphabet);
    printf("Position %i\n",pos);
    char newchar = change(c,alphabet,n);
    printf("Newchar %c\n",newchar);



    return 0;
}










char* replaceWord(const char* s, const char* oldW,
                  const char* newW)
{
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
  
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
  
            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }
  
    // Making new string of enough length
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
  
    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }
  
    result[i] = '\0';
    return result;
}






void upper(char str[]){
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        /*
         * If current character is lowercase alphabet then
         * convert it to uppercase.
         */
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
     }
 }


void normalized_text(char text[],char alphabet[],char newstring[]){//def normalize_text(text):
    char c[] = " ";
    char d[] = "";
    int i,j;
    text = replaceWord(text, c, d);
    upper(text);
    int limit = strlen(text);
    int limitA = strlen(alphabet);

    for(i=0;i < limit;i++){
        for(j=0;j<limitA;j++){
            if(text[i] == alphabet[j]){
                strncat(newstring,&text[i],1);
            }

        }

    }
    //return result;



}

void imprimir(char text[]){
    int i =0;
    int limit = strlen(text);
    for(i =0;i<limit;i++){
        printf("alfabeto: %c\n",text[i]);

    }
}


int char_to_pos(char txt[]){
    int pos = ordc(txt)-65;
    return pos;
}





char change(char character[],char *charset,int n){//def change(char,charset=alphabet,n=0):

    int pos = char_to_pos(character,charset)+n;
    char newchar = charset[pos % 26];
    return newchar; 
}


void set_intern_position(struct enigmaM3 *enigma, char pos_int[]){
    enigma -> intern_position = pos_int;
}

void set_plugboard(struct enigmaM3 *enigma, char plugboard[]){
    enigma -> plugboard = plugboard;
}

void reset(struct enigmaM3 *enigma, char lastopts[]){
    enigma -> opts  = lastopts;
}

char apply_rotor(char character[],int n,char *rotor,char *alphabet ){
    char new_character = change(character,rotor,n);
    return change(character,alphabet,-n);
}


char reflecting(char character[],char *alphabet,struct enigmaM3 *enigma   ){
    int n = 0;
    char newchar = change(character,enigma.reflector,n) ;
    return newchar;
}


void rotor_forward(struct enigmaM3 *enigma,char *alphabet){
    for(int i = 0;i<2;i++){
        if(enigma.pos_ini[1] == enigma.notch[enigma.rotors[1]][0]){
            enigma.pos_ini[0] = change(enigma.pos_ini[0],alphabet,1);
            enigma.pos_ini[1] = change(enigma.pos_ini[1],alphabet,1);
        }
    }

    for(int i = 0;i<2;i++){
            if(enigma.pos_ini[2] == enigma.notch[enigma.rotors[2]][0]){
                enigma.pos_ini[1] = change(enigma.pos_ini[1],alphabet,1);
            }
        }
    enigma.pos_ini[2] = change(enigma.pos_ini[2],alphabet,1);
}

int ordc(char character[]){
    
    int i= (int)character[0];
    return i;
    
}

char apply_plugboard(struct enigmaM3 *enigma,char character[],char plugboard[]){
    int limit1 = sizeof(plugboard)/sizeof(int);
    for(int i =0;i<limit1;i++){
        if character == i[0]{
            char newchar[] = i[1];
        }
        if character == i[1]{
            char newchar[] = i[0];
        }
    }
    return newchar;
}

char cipher_letter(struct enigmaM3 *enigma,char character[],char plugboard[],char *alphabet){
    char character2 = apply_plugboard(*enigma,character,plugboard);
    rotor_forward(*enigma,alphabet);
    for(int i=2; i>=0; i--){
        int n = ordc(enigma.pos_ini[i]) - ordc(enigma.intern_position[i]);
        character2 = apply_rotor(character2,n,con_rotors[enigma.rotors[i]],alphabet);

    }
    character2 = reflecting(character2,alphabet,enigma)
    for(int i = 0;i>3;i++){
        n = ordc(enigma.pos_ini[i]) - ordc(enigma.intern_position[i]);
        character2 = apply_rotor(character2,n,rotors_return[enigma.rotors[i]],alphabet);
    }
    character2 = apply_plugboard(enigma,character2,plugboard)
    return character2



}

     
char cipher(chat text[],struct enigmaM3 *enigma,char plugboard[],char *alphabet){
    int limit = strlen(txt);
    char output[limit];
    for(int = 0; i<limit;i++){
        char ch = cipher_letter(enigma,text[i],plugboard,alphabet);
        strncat(output, &ch, 1);
    }
    return output;

}


char  decipher(chat text[],struct enigmaM3 *enigma,char plugboard[],char *alphabet){

    char decode[] = cipher(text,enigma,plugboard,alphabet);

    return decode;



}
