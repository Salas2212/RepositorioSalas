/*
 * Autor: Juan Esteban Salas
 * Codigo: 8975783
 * Proyecto Final "Big Integer"
 * Archivo: main.cpp
*/

#include "BigInteger.h"

bool contieneSoloCeros(string& cadena) {
    bool res = true;
    for (char c : cadena) {
        if (c != '0') {
            res = false;
        }
    }
    return res;
}

int main() {
    string bigInteger1, bigInteger2;
    string pEntera1, pDecimal1, pEntera2, pDecimal2, line;
    int cases = 1;
    while(getline(cin, line)){
        stringstream sp(line);

        sp >> bigInteger1;
        sp >> bigInteger2;
        stringstream n1(bigInteger1);
        stringstream n2(bigInteger2);

        getline(n1, pEntera1, '.');
        getline(n1, pDecimal1);
        getline(n2, pEntera2, '.');
        getline(n2, pDecimal2);


        BigInteger biEntero1(pEntera1);
        BigInteger biEntero2(pEntera2);


        if(biEntero1 < biEntero2){
            printf("Case %d: Smaller\n", cases);
        }
        else if(biEntero2 < biEntero1){
            printf("Case %d: Bigger\n", cases);
        }
        else{
            int tam1 = pDecimal1.length(), tam2 = pDecimal2.length();
            int cont1 = 0, cont2 = 0;
            if(contieneSoloCeros(pDecimal1) && contieneSoloCeros(pDecimal2)){
                printf("Case %d: Same\n", cases);
            }
            else{
                for(int i = 0; i < tam1; i++){
                    if( pDecimal1[i] == '0'){
                        cont1 +=1;
                    }
                    else if( pDecimal1[i] != '0'){
                        pDecimal1 = pDecimal1.substr(i);
                        i = tam1;
                    }
                }
                for(int i = 0; i < tam2; i++){
                    if( pDecimal2[i] == '0'){
                        cont2 +=1;
                    }
                    else if( pDecimal2[i] != '0'){
                        pDecimal2 = pDecimal2.substr(i);
                        i = tam2;

                    }
                }
                if(pDecimal1.length() < pDecimal2.length()){
                    pDecimal1.resize(pDecimal2.length(),'0');
                }
                else if(pDecimal1.length() > pDecimal2.length()){
                    pDecimal2.resize(pDecimal1.length(),'0');
                }
                BigInteger biDecimal1(pDecimal1);
                BigInteger biDecimal2(pDecimal2);
                if(cont1 > cont2){
                    printf("Case %d: Smaller\n", cases);
                }
                else if(cont1 < cont2){
                    printf("Case %d: Bigger\n", cases);
                }
                else{
                    if(biDecimal1 < biDecimal2){
                        printf("Case %d: Smaller\n", cases);
                    }
                    else if(biDecimal2 < biDecimal1){
                        printf("Case %d: Bigger\n", cases);
                    }
                }
            }
            
        }
        cases++;
    
    }
    
    return 0;
}