/*
Nombre: Juan Esteban Salas
Codigo: 8975783
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int G, P, nP, S;
    vector<vector<int>> races;
    vector<vector<int>> scoringT;
    vector<vector<int>> classT;
    while(scanf("%d %d\n", &G, &P) == 2 && (G != 0 || P != 0)){
        for(int i = 0; i < G; i++){
            vector<int> file;
            vector<int> file2;
            for(int j = 0; j < P; j++){
                scanf("%d", &nP);
                file.push_back(nP);
                file2.push_back(0);
            }
            races.push_back(file);
            classT.push_back(file2);
        }

        scanf("%d\n", &S);
        int k = 0;
        vector<int> posiciones;
        while(S--){
            vector<int> fila;
            int rw, pj;
            scanf("%d", &rw);
            for(int i = 0; i < rw; i++){
                scanf("%d", &pj);
                fila.push_back(pj);
                
            }
            scoringT.push_back(fila);
            for (int j = 0; j < scoringT[k].size(); j++) {
                for (int x = 0; x < races.size(); x++){
                    for(int y = 0; y < races[x].size(); y++){
                        classT[x][y] = 0;
                        if(j+1 == races[x][y]){
                            classT[x][y] += scoringT[k][j];
                        }
                    }
                }
            }
            vector<int> result(classT[0].size(), 0);
            for (int i = 0; i < classT.size(); i++) {
                for (int j = 0; j < classT[i].size(); j++) {
                    result[j] += classT[i][j];
                }
            }

            int max_num = 0;
            for (int i = 0; i < result.size(); i++) {
                if (result[i] > max_num) {
                    max_num = result[i];
                    posiciones.clear();
                    posiciones.push_back(i+1);
                }
                else if (result[i] == max_num) {
                    posiciones.push_back(i+1);
                }
            }
            
            for (int i = 0; i < posiciones.size(); i++) {
                cout << posiciones[i] << " ";
            }
            cout << "\n";
            posiciones.clear();
            result.clear();
            for(int i= 0; i < classT.size();i++){
                fill(classT[i].begin(), classT[i].end(), 0);
            }
            
            k++;
            
        }   
    }   
    return 0;
}