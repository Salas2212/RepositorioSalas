/*
 * Nombre: Juan Esteban Salas
 * Codigo: 8975783
 * Archivo: keyboard.cpp
 * Complejidad: La complejidad de este programa es de O(C*L) donde C es el numero casos a probar y L es la longitud que puede tener cada linea ya que tenemos un for que recorre cada letra, por lo tanto en el pero de los casos puede ser 100000.
*/

#include <iostream>
#include <queue>
#include <deque>

using namespace std;


int main(){
    string input;
    bool Front = false;
    while( getline(cin, input) ){
        deque<char> beiju, ans;
        for(int i = 0; i < input.length(); i++){
            char l = input[i];
            if(l == '['){
                Front = true;
                ans.insert(ans.begin(), beiju.begin(), beiju.end());
                beiju.clear();
            }
            else if(l == '[' && Front){
                ans.insert(ans.begin(), beiju.begin(), beiju.end());
                beiju.clear();
            }
            else if(l == ']'){
                beiju.insert(beiju.end(), ans.begin(), ans.end());
                ans.clear();
                Front = false;
            }
            else{
                beiju.push_back(l);
                
            }
        }
        beiju.insert(beiju.end(), ans.begin(), ans.end());
        
        while (!beiju.empty()) {
            cout << beiju.front();
            beiju.pop_front();
        }
        cout << endl;
    }
    return 0;
}
