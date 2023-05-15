/*
 * Nombre: Juan Esteban Salas
 * Codigo: 8975783
 * Archivo: queue.cpp
 * Complejidad: La complejidad del programa es O(P + C*T) donde P es el tamaño de la población, este esta limitado a 1000 personas. C es el numero de comandos, en este caso el max puede ser 1000, y T es el tamaño de la cola, ya que la funcion find para encontrar el ciudadano tiene complejidad O(T).
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void llenarCola(deque<int> &queue, int &P);

int main(){
    int P, C, Case = 1;
    deque<int> citizenQueue;
    while (cin >> P >> C && (P != 0 || C != 0)){
        cout << "Case " << Case << ":" << endl;
        llenarCola(citizenQueue,P);
        for(int j = 0; j < C; j++){
            char command;
            cin >> command;
            if(command == 'N'){
                cout << citizenQueue.front() << endl;
                citizenQueue.push_back(citizenQueue.front());
                citizenQueue.pop_front();
            } else if(command == 'E'){
                int citizen;
                cin >> citizen;
                auto it = find(citizenQueue.begin(),citizenQueue.end(), citizen);
                if (it != citizenQueue.end()) {
                    citizenQueue.erase(it);
                }
                citizenQueue.push_front(citizen);
            }
        }
        Case++;
    }
    
    return 0;
}

void llenarCola(deque<int> &queue, int &P){
    queue.clear();
    for (int i = 0; i < min(P, 1000); i++) {
        queue.push_back(i+1);
    }
}
