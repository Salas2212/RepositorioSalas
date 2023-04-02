/*
Nombre: Juan Esteban Salas
Codigo: 8975783
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    char symbol[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','.',',','?','\'','!','/','(',')','&',':',';','=','+','-','_','"','@'};
    string code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};
    string linea, codigo, mensaje;
    int casos, t = 53;
    scanf("%d", &casos);
    for(int i = 0; i <= casos; i++){
        getline(cin,linea);
        int Long = linea.length();
        for(int j = 0; j < Long; j++){
            if(linea[j] != ' '){
                codigo += linea[j];
            }
            if((linea[j] == ' ') || j+1 == Long){
                for(int k = 0; k < t; k++){
                    if(codigo == code[k]){
                        mensaje += symbol[k];
                    }
                }
                if(linea[j] == ' ' && linea[j-1] == ' '){
                    mensaje+= " ";
                }
                codigo.clear();
            }
            if(j+1 == Long){
                printf("Message #%d\n", i);
                printf("%s\n",mensaje.c_str());
                if(i != casos){
                    printf("\n");
                }
                mensaje.clear();
            }
        }
        
    }
    return 0;
}