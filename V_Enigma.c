#include <stdio.h>
//#include <mpi.h>
#include <stdlib.h>
#include <string.h>

int main(){
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

    // short %d Tipo entero 
    // int %d Tipo entero 
    // long int %ld Tipo entero 
    // long long int %Ld Tipo entero
    // float %f Coma flotante de baja precisión 
    // double %f Coma flotante de mayor precisión
    // long double %Lf Coma flotante de mayor precisión 
    // char %c ó %s Caracter(es)

    // esto es el class enigmaM3 de .py
    typedef struct enigmaM3{
        char reflector[1]; // Es una letra: "B"
        /*(Es tres porque en el código python a lo más que llega es a 2 pero el otro
        espacio en el arreglo es para \0 "espacio vacio por defeto" ) */
        int rotors [3]; // Es una tupla: (4, 1, 3)
        char plugboard[6][2]; // Arreglo de tuplas: [('A','M'),('F','I'),('N','V'),('P','S'),('T','U'),('W','Z')]
        char pos_ini[3]; // Posición inicio se actualiza con cada caracter 
        char intern_position[3]; // VALOR INICIAL = {"A", "A", "A"};
        char notch[8][2]; // VALOR INICIAL = (('Q',),('E',),('V',),('J',),('Z',),('Z','M'),('Z','M'),('Z','M'));
        char opts[5]; // Guardar la configuración inicial

    }enigmaM3;
    
    return 0;
}