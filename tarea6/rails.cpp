/*
 * Nombre: Juan Esteban Salas
 * Codigo: 8975783
 * Archivo: rails.cpp
 * Complejidad: La complejidad de este programa es O(N^2), Esto ya que hay un ciclo for que se ejecuta N*2 veces, y este ciclo esta dentro de un while que itera N veces debido a que esta dentro de otro while. Por lo tanto su complejidad es O(N^2)
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int N,num,cont;
    bool ex;
    while (cin >> N && N != 0)
    {
        deque<int> coaches;
        string line;
        deque<int> cases;
        while ((getline(cin >> ws,line)) && (line != "0")){
            cont = 0;
            stringstream ss(line);
            while(ss >> num){
                cases.push_back(num);
            }
            for(int i = 1; i <= N*2; i++){
                ex = true;
                if(coaches.empty()){
                    coaches.push_back(i);
                }
                while(ex){
                    if(coaches.back() == cases.front()){
                        coaches.pop_back();
                        cases.pop_front();
                        cont++;
                    }
                    else if((i <= N) && (!coaches.empty())){
                        coaches.push_back(i);
                        ex = false;
                    }
                    else if((i > N) && (coaches.back() != cases.front())){
                        ex = false;
                        i = N*2;
                    }
                    if(coaches.empty()){
                        ex = false;
                    }
                    if(cont == N){
                        ex = false;
                        i = N*2;
                    }
                }
            }
            if(cont == N){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
            coaches.clear();
            cases.clear();
        }
        cout << endl;
        
    }
    
    return 0;
}
