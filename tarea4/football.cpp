/*
Nombre: Juan Esteban Salas
Codigo: 8975783
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;


string minuscula(string str){
    for(int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

void intercambiarEquipos(int i, int j, int nP[], int nGP[], int nSCG[], int nSUG[], int nGD[], string equipos[]) {
    swap(nP[i], nP[j]);
    swap(nGP[i], nGP[j]);
    swap(nSCG[i], nSCG[j]);
    swap(nSUG[i], nSUG[j]);
    swap(nGD[i], nGD[j]);
    swap(equipos[i], equipos[j]);
}

int main(){
    int nEquipos, nPartidos;
    string nombre;
    while (scanf("%d %d\n", &nEquipos, &nPartidos) == 2 && (nEquipos != 0 || nPartidos != 0)){
        int nP[nEquipos] = {}, nGP[nEquipos] = {}, nSCG[nEquipos] = {}, nSUG[nEquipos] = {}, nGD[nEquipos] = {};
        string equipos[nEquipos] = {};

        for(int i = 0; i < nEquipos; i++){
            getline(cin, nombre);
            equipos[i] = nombre;
        }

        sort(equipos, equipos+nEquipos);
        
        for(int i = 0; i < nPartidos; i++){
            int golE1, golE2;
            string equipo1, equipo2;
            cin >> equipo1 >> golE1 >> ws;
            cin.ignore();
            cin >> golE2 >> equipo2;
            bool find1 = false, find2 = false;
            for(int j = 0; j < nEquipos; j++){
                if(find1 == false){
                    if(equipos[j] == equipo1){
                        if(golE1 > golE2){
                            nP[j] += 3;
                        }
                        else if(golE1 == golE2){
                            nP[j] += 1;
                        }
                        nGP[j] += 1;
                        nSCG[j] += golE1;
                        nSUG[j] += golE2;
                        nGD[j] += golE1 - golE2;
                        find1 = true;
                    }
                }
                if(find2 == false){
                    if(equipos[j] == equipo2){
                        if(golE2 > golE1){
                            nP[j] += 3;
                        }
                        else if(golE1 == golE2){
                            nP[j] += 1;
                        }
                        nGP[j] += 1;
                        nSCG[j] += golE2;
                        nSUG[j] += golE1;
                        nGD[j] += golE2 - golE1;
                        find2 = true;
                    }
                }
                    
            }
            
        }
        //Ordenar
        
        for(int i = 0; i < nEquipos; i++){
            int j;
            j = i + 1;
            if(j != nEquipos){
                if(nP[i] < nP[j]){
                    intercambiarEquipos(i,j,nP,nGP,nSCG,nSUG,nGD,equipos);
                    i = -1;
                }
                else if(nP[i] == nP[j]){
                    if(nGD[i] < nGD[j]){
                        intercambiarEquipos(i,j,nP,nGP,nSCG,nSUG,nGD,equipos);
                        i = -1;
                    }
                    else if(nGD[i] == nGD[j]){
                        if(nSCG[i] < nSCG[j]){
                            intercambiarEquipos(i,j,nP,nGP,nSCG,nSUG,nGD,equipos);
                            i = -1;
                        }
                        else if(nSCG[i] == nSCG[j]){
                            if(nSUG[i] > nSUG[j]){
                                intercambiarEquipos(i,j,nP,nGP,nSCG,nSUG,nGD,equipos);
                                i = -1;
                            }
                            
                        }
                        
                    }
                }
            }

            
        }

        for(int i = 0; i < nEquipos; i++){
            if(nGP[i] == 0){
                string possible = "N/A";
                printf("%2d. %15s %3d %3d %3d %3d %3d %6s\n", i+1, equipos[i].c_str(), nP[i], nGP[i], nSCG[i], nSUG[i], nGD[i], possible.c_str());
            }
            else{
                double percentage, games = (nGP[i])*3, points = nP[i];
                percentage = (points/games) * 100;
                if(i != 0){
                    if(nP[i] == nP[i-1] && nGD[i] == nGD[i-1] && nSCG[i] == nSCG[i-1] && nSUG[i] == nSUG[i-1]){
                        printf("    %15s %3d %3d %3d %3d %3d %6.2f\n", equipos[i].c_str(), nP[i], nGP[i], nSCG[i], nSUG[i], nGD[i], percentage);
                    }
                    else{
                        printf("%2d. %15s %3d %3d %3d %3d %3d %6.2f\n", i+1, equipos[i].c_str(), nP[i], nGP[i], nSCG[i], nSUG[i], nGD[i], percentage);
                    }
                }
                else{
                    printf("%2d. %15s %3d %3d %3d %3d %3d %6.2f\n", i+1, equipos[i].c_str(), nP[i], nGP[i], nSCG[i], nSUG[i], nGD[i], percentage);
                }
        
                
            }
        }

        //Imprimir
        
        printf("\n");
    }
    
    return 0;
}