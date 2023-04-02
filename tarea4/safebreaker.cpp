/*
Nombre: Juan Esteban Salas
Codigo: 8975783
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main(){
    int N, G, code, wrongP, correctD, CC;
    bool state = true;
    string cW;
    cin >> N;
    for(int i= 0; i < N && state == true; i++){
        cin >> G;
        for(int j= 0; j < G; j++){
            cin >> code >> cW;
            sscanf(cW.c_str(), "%d/%d", &correctD, &wrongP);
            if(correctD == 4){
                CC = code;
                state = false;
            }
        }
    }
    
    return 0;
}