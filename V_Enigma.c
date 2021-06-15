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
char* reflectors [3][8] = { {"E", "J", "M", "Z", "A", "L", "Y", "X" , "V", "B", "W", 
                            "F", "C", "R", "Q", "U", "O", "N", "T", "S", "P", "I", "K",
                            "H", "G", "D"},     
                            {"Y", "R", "U", "H", "Q", "S", "L", "D", "P", "X", "N", "G",
                            "O", "K", "M", "I", "E", "B", "F", "Z", "C", "W", "V", "J",
                            "A", "T"},        
                            {"F", "V", "P" "J", "I", "A", "O", "Y", "E", "D", "R", "Z",
                            "X", "W", "G", "C","T", "K", "U" ,"Q", "S", "B", "N", "M", "H", "L"} }; 

// Rotores: Ocho posibles
char* con_rotors [8][26] = { {"E", "K", "M", "F", "L", "G", "D", "Q", "V", "Z", "N", "T", "O",
                        "W", "Y", "H", "X", "U", "S", "P", "A", "I", "B", "R", "C", "J"},        
                        {"A", "J", "D", "K", "S", "I", "R", "U", "X", "B", "L", "H", "W",
                        "T", "M", "C", "Q", "G", "Z", "N", "P", "Y", "F", "V", "O", "E"},        
                        {"B", "D", "F", "H", "J", "L", "C", "P","R", "T", "X", "V", "Z",
                        "N", "Y", "E", "I", "W", "G", "A", "K", "M", "U", "S", "Q", "O"},        
                        {"E", "S", "O", "V", "P", "Z", "J", "A", "Y", "Q", "U", "I", "R",
                        "H", "X", "L", "N", "F", "T", "G", "K", "D", "C", "M", "W", "B"},
                        {"V", "Z", "B", "R", "G", "I", "T", "Y", "U", "P", "S", "D", "N",
                        "H", "L", "X", "A", "W", "M", "J", "Q", "O", "F", "E", "C", "K"},
                        {"J", "P", "G", "V", "O", "U", "M", "F", "Y", "Q", "B", "E", "N",
                        "H", "Z", "R", "D", "K", "A", "S", "X", "L", "I", "C", "T", "W"},
                        {"N", "Z", "J", "H", "G", "R", "C", "X", "M", "Y", "S", "W", "B",
                        "O", "U", "F", "A", "I", "V", "L", "P", "E", "K", "Q", "D", "T"},
                        {"F", "K", "Q", "H", "T", "L", "X", "O", "C", "B", "J", "S", "P",
                        "D", "Z", "R", "A", "M", "E", "W", "N", "I", "U", "Y", "G", "V"} };       

// Rotores de retorno: Ocho posibles
char* rotors_return [8][26] = { {"U","W", "Y", "G", "A", "D", "F", "P", "V", "Z", "B", "E", "C",
                                "K", "M", "T","H", "X", "S", "L", "R", "I", "N", "Q", "O", "J"},
                                {"A", "J", "P", "C", "Z", "W", "R", "L", "F", "B", "D", "K", "O", 
                                "T", "Y", "U", "Q", "G", "E", "N", "H", "X", "M", "I", "V", "S"},
                                {"T", "A", "G", "B", "P", "C", "S", "D", "Q", "E", "U", "F", "V",
                                "N", "Z", "H", "Y", "I", "X", "J", "W", "L", "R", "K", "O", "M"},
                                {"H", "Z", "W", "V", "A", "R", "T", "N", "L", "G", "U", "P", "X", 
                                "Q", "C", "E", "J", "M", "B", "S", "K", "D", "Y", "O", "I", "F"},
                                {"Q", "C", "Y", "L", "X", "W", "E", "N", "F", "T", "Z", "O", "S",
                                "M", "V", "J", "U", "D", "K", "G", "I", "A", "R", "P", "H", "B"},
                                {"S", "K", "X", "Q", "L", "H", "C", "N", "W", "A", "R", "V", "G",
                                "M", "E", "B", "J", "P", "T", "Y", "F", "D", "Z", "U", "I", "O"},
                                {"Q", "M", "G", "Y", "V", "P", "E", "D", "R", "C", "W", "T", "I",
                                "A", "N", "U", "X", "F", "K", "Z", "O", "S", "L", "H", "J", "B"},
                                {"Q", "J", "I", "N", "S", "A", "Y", "D", "V", "K", "B", "F", "R",
                                "U", "H", "M", "C", "P", "L", "E", "W", "Z", "T", "G", "X", "O"} };

// Alfabeto
char* alphabet[26] = {"A", "B", "C", "D", "E", "F", "G",
                    "H", "I", "J", "K", "L", "M", "N", "O", "P",
                    "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};




int main(){
    /*
    // esto es el class enigmaM3 de .py
    typedef struct enigmaM3{
        char *reflector[1]; // Es una letra: "B"
        // (Es tres porque en el código python a lo más que llega es a 2 pero el otro
        // espacio en el arreglo es para \0 "espacio vacio por defeto" ) 
        int *rotors[3]; // Es una tupla: (4, 1, 3)
        char *plugboard[6][2]; // Arreglo de tuplas: [('A','M'),('F','I'),('N','V'),('P','S'),('T','U'),('W','Z')]
        char *pos_ini[3]; // Posición inicio se actualiza con cada caracter 
        char *intern_position[3]; // VALOR INICIAL = {"A", "A", "A"};
        char *notch[8][2]; // VALOR INICIAL = (('Q',),('E',),('V',),('J',),('Z',),('Z','M'),('Z','M'),('Z','M'));
        char *opts[5]; // Guardar la configuración inicial

    }enigmaM3;*/

    /*
    printf("Reflector M3: %s\n", myMachine.reflector[0]);
    printf("Rotors M3: %d\n", myMachine.rotors[1]);
    printf("Plugboard M3: %s\n",  myMachine.plugboard[5][0]);
    printf("pos_ini M3: %s\n", myMachine.pos_ini[1]);
    printf("inter_position M3: %s\n", myMachine.intern_position[1]);
    printf("notch M3: %s%s\n", myMachine.notch[6][0], myMachine.notch[6][1]);
    printf("opts M3: %s\n", myMachine.opts[1][0]);
    */

    // Configuración inicial de la enigmaM3
    char *reflector[1] = {'B'}; 
    int *rotors[3] = {4, 1, 3}; 
    char *plugboard[6][2] = {{'A','M'},{'F','I'},{'N','V'},{'P','S'},{'T','U'},{'W','Z'}};
    char *pos_ini[3] = {'A', 'B', 'C'}; 
    char *intern_position[3] = {'A', 'A', 'A'}; 
    char *notch[8][2] = { {'Q', '\0'}, {'E', '\0'}, {'V', '\0'}, {'J', '\0'}, {'Z', '\0'}, {'Z', 'M'}, {'Z', 'M'}, {'Z', 'M'} };
    char *opts[5] = {rotors, reflector, pos_ini, intern_position, plugboard};

    //struct enigmaM3 myMachine = {reflector, rotors, plugboard, pos_ini, intern_position, notch, opts};


    printf("------------------------------------\n");
    printf("-----------------EnigmaM3-----------\n");
    printf("reflector: %s\n", &reflector[0]);
    printf("rotors: %d\n", rotors[1]);
    printf("plugboard: %s\n", &plugboard[5][0]);
    printf("pos_ini: %s\n", &pos_ini[1]);
    printf("intern_position: %s\n", &intern_position[1]);
    printf("notch: %s%s\n", &notch[6][0], &notch[6][1]);
    printf("opts: %s\n", &opts[1][0]);
    printf("-----------------------------------\n");

    printf("%s\n", alphabet[0]);
    printf("%s\n", rotors_return[0][1]);
    printf("%s\n", reflectors[0][0]);
    //printf("reflectors %s\n", &reflectors[1]);
    //char_to_pos(reflector);
    char result = set_reflector(reflector[0]);
    printf("result: %s\n", &result)
    
    return 0;
}


int ordc(char character[]){
    
    int i = (int)character[0];
    printf("!!ordc: %d\n", i);
    return i;
}

int char_to_pos(char txt[]){
    int pos = ordc(txt)-65;
    printf("!!!!POS: %d\n", pos);
    return pos;
    }

char set_reflector(char txt[]){
    char self_reflector = reflectors[char_to_pos(txt)][char_to_pos(txt)];
    printf("ENTRE!!!");
    return self_reflector; 
    }
