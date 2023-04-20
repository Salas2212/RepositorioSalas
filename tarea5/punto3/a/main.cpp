
#include "lista.h"
#include <iostream>

using namespace std;

//Punto a
void insertarEnListaOrdenada(Lista &l,int v){
  if(l.vaciaLista()){ //O(1)
    l.anxLista(v); //O(n) Ya que la funcion anxLista recorre todos los nodos hasta llegar al final - (n es el tamaño de la lista)
  }
  else{
    int pos = 1, n, lg = l.longLista(); //O(n) La funcion longLista cuenta todas las posiciones de la lista para determinar su longitud - (n es el tamaño de la lista)
    bool run = true; //O(1)
    for(int i = 0; i < lg && run; i++){ //O(1)
      n = l.infoLista(i); //En el mejor caso: Es el primer elemento de la lista O(1) || En el peor caso: El ultimo elemento (n) - (n es el tamaño de la lista)
      if(v > n){
        pos = i + 1; //O()
      }
      else{
        run = false; //O(1)
      }
    }
    if(pos == lg+1){//Mejor caso: 0 || Peor caso: O(1)
      l.anxLista(v); //O(n) Ya que la funcion anxLista recorre todos los nodos hasta llegar al final - (n es el tamaño de la lista)
    }
    else{//O(n) Se ejecuta todas las posiciones de menos la ultima
      l.insLista(v,pos); //O(n) La funcion recorre la lista hasta llegar a la posición
    }
  }
}


int main(){
  Lista l1;
  insertarEnListaOrdenada(l1,0);
  insertarEnListaOrdenada(l1,3);
  insertarEnListaOrdenada(l1,2);
  insertarEnListaOrdenada(l1,4);
  insertarEnListaOrdenada(l1,5);
  insertarEnListaOrdenada(l1,1);
  insertarEnListaOrdenada(l1,3);

  for (int i = 1; i < l1.longLista() + 1; i++)
  {
    printf("%d ", l1.infoLista(i));
  }
  
  return 0;
}
