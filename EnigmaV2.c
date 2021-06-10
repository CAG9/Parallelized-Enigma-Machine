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


int char_to_pos(char txt[],char alphabet[]){//def char_to_pos(char):       
    int i =0;
    int limit = strlen(txt);
    int pos;
    for(i=0;i<limit;i++){
        if(txt[0] == alphabet[i]){
            pos =  i;
            break;
        }
    }
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


char reflecting(char character[],char *alphabet,char *reflector   ){
    int n = 0;
    char newchar = change(character,enigma.reflector,n) ;
    return newchar;
}


  
























