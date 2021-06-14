#include <stdio.h>
//#include <mpi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// short %d Tipo entero 
// int %d Tipo entero 
// long int %ld Tipo entero 
// long long int %Ld Tipo entero
// float %f Coma flotante de baja precisión 
// double %f Coma flotante de mayor precisión
// long double %Lf Coma flotante de mayor precisión 
// char %c ó %s Caracter(es)


// Reflectores: Tres posibles
// Reflector A, Reflector B, Reflector C
char* reflectors [] = {"EJMZALYXVBWFCRQUONTSPIKHGD",     
        "YRUHQSLDPXNGOKMIEBFZCWVJAT",        
        "FVPJIAOYEDRZXWGCTKUQSBNMHL"}; 

// Rotores: Ocho posibles
char* con_rotors [] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",        
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",        
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",        
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",        
        "VZBRGITYUPSDNHLXAWMJQOFECK",      
        "JPGVOUMFYQBENHZRDKASXLICTW",       
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",        
        "FKQHTLXOCBJSPDZRAMEWNIUYGV"};       

// Rotores de retorno: Ocho posibles
char* rotors_return [] = {"UWYGADFPVZBECKMTHXSLRINQOJ",
        "AJPCZWRLFBDKOTYUQGENHXMIVS",
        "TAGBPCSDQEUFVNZHYIXJWLRKOM",
        "HZWVARTNLGUPXQCEJMBSKDYOIF",
        "QCYLXWENFTZOSMVJUDKGIARPHB",
        "SKXQLHCNWARVGMEBJPTYFDZUIO",
        "QMGYVPEDRCWTIANUXFKZOSLHJB",
        "QJINSAYDVKBFRUHMCPLEWZTGXO"};

// Alfabeto
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main(){

    // esto es el class enigmaM3 de .py
    typedef struct enigmaM3{
        char *reflector[1]; // Es una letra: "B"
        /*(Es tres porque en el código python a lo más que llega es a 2 pero el otro
        espacio en el arreglo es para \0 "espacio vacio por defeto" ) */
        int *rotors[3]; // Es una tupla: (4, 1, 3)
        char *plugboard[6][2]; // Arreglo de tuplas: [('A','M'),('F','I'),('N','V'),('P','S'),('T','U'),('W','Z')]
        char *pos_ini[3]; // Posición inicio se actualiza con cada caracter 
        char *intern_position[3]; // VALOR INICIAL = {"A", "A", "A"};
        char *notch[8][2]; // VALOR INICIAL = (('Q',),('E',),('V',),('J',),('Z',),('Z','M'),('Z','M'),('Z','M'));
        char *opts[5]; // Guardar la configuración inicial

    }enigmaM3;
    
    char *reflector[1] = {'B'}; 
    int *rotors[3] = {4, 1, 3}; 
    char *plugboard[6][2] = {{'A','M'},{'F','I'},{'N','V'},{'P','S'},{'T','U'},{'W','Z'}};
    char *pos_ini[3] = {'A', 'B', 'C'}; 
    char *intern_position[3] = {'A', 'A', 'A'}; 
    char *notch[8][2] = { {'Q', '\0'}, {'E', '\0'}, {'V', '\0'}, {'J', '\0'}, {'Z', '\0'}, {'Z', 'M'}, {'Z', 'M'}, {'Z', 'M'} };
    char *opts[5] = {rotors, reflector, pos_ini, intern_position, plugboard};

    struct enigmaM3 myMachine = {&reflector, &rotors, &plugboard,
                        &pos_ini, &intern_position, &notch, &opts};

    printf("reflector: %s\n", &reflector[0]);
    printf("rotors: %d\n", rotors[1]);
    printf("plugboard: %s\n", &plugboard[5][0]);
    printf("pos_ini: %s\n", &pos_ini[1]);
    printf("intern_position: %s\n", &intern_position[1]);
    printf("notch: %s%s\n", &notch[6][0], &notch[6][1]);
    printf("opts: %s\n", &opts[1][0]);
    printf("------------------------------------\n");
    printf("-----------------EnigmaM3-----------\n");
    printf("Reflector M3: %s\n", myMachine.reflector[0]);
    printf("Rotors M3: %ls\n", myMachine.rotors[0]);
    
    return 0;
}


/*


int ordc(char character[]){
    
    int i= (int)character[0];
    return i;
    
}

int char_to_pos(char txt[]){
    int pos = ordc(txt)-65;
    return pos;
    }

void set_reflector(struct enigmaM3 self_reflector, char txt[]){
	//The function set_reflector from pythonenigma.py
	// * parameters: 
	// * self_reflector type: enigmaM3
	// * txt type: char
    // * -> self_reflector corresponds to the parameter
    //  * reflector from our class enigmaM3
    struc enigmaM3 self_reflector; 
	self_reflector = reflectors[char_to_pos(txt)];
    return self_reflector;
    }

*/