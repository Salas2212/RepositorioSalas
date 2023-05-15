/*
 * Nombre: Juan Esteban Salas
 * Codigo: 8975783
 * Archivo: word.cpp
 * Nota: Segun la logica que aplique para el desarrollo de este problema, no entiendo el porque no me dan los casos de prueba.
 * Complejidad: O(P*L*Z) = El programa tiene un bucle anidado, donde primero itera sobre la cantidad de palabras (P = 1000), luego la cantidad de letras (L = 25) y por ultimo la cantidad de letras de cada puzzle (Z = 20). El resto del codigo es constante O(1)
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int tamW, tamP, cont, contP;
    bool find;
    string word;
    vector<string> dictionary;
    while ((cin >> word) && (word != "#")){
        dictionary.push_back(word);
    }
    string line;
    deque<char> puzzle;
    deque<char> copyPuzzle;
    while ((getline(cin >> ws,line)) && (line != "#")){
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        tamP = line.length();
        cont = 0;
        for(int j = 0; j < tamP; j++){
            puzzle.push_back(line[j]);
        }
        copyPuzzle = puzzle;
        for(int i = 0; i < dictionary.size(); i++){
            tamW = dictionary[i].length();
            contP = 0;
            if(tamP >= tamW){
                for(int j = 0; j < tamW; j++){
                    find = false;
                    for (deque<char>::iterator it = puzzle.begin(); it < puzzle.end(); ++it) {
                        if (*it == dictionary[i][j] && find == false) {
                            puzzle.erase(it);
                            contP++;
                            find = true;
                        }
                    } 
                }
                if(contP == tamW){
                    cont++;
                }
            }
            else{
                i = dictionary.size();
            }
            puzzle = copyPuzzle;
            
        }
        cout << cont << endl;
        puzzle.clear();
    }
    return 0;
}
