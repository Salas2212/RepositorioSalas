
#include "lista.h"
#include <iostream>

using namespace std;

//Punto 1
Elemento contarOcurrencias(Lista &l, Elemento v){
  Elemento contador = 0, numero;
  for(int i = 1; i < l.longLista(); i++){
    numero = l.infoLista(i);
    if (numero == v)contador++;
  } 
  return contador;
}
//Complejidad: O(n)
//Siendo n el tamaño de la lista que recibe, en el mejor de los casos solo  se ejecuta 1 vez, en el peor n veces.


//Punto 2
Lista obtenerMenores(Lista &l, Elemento v){
  Lista nMenores;
  Elemento numero;
  for (int i = 1; i < l.longLista(); i++){
    numero = l.infoLista(i);
    if(numero < v){
      nMenores.anxLista(numero);
    }
  }
  return nMenores;
}
//Complejidad: O(n)
//Siendo n el tamaño de la lista que recibe, por lo tanto, se ejecuta n veces.

int main(){
  Lista l1;
  l1.anxLista(5);
  l1.anxLista(5);
  l1.anxLista(4);
  l1.anxLista(6);
  l1.anxLista(5);
  l1.anxLista(3);
  l1.anxLista(2);
  
  Elemento cOcurrencias = contarOcurrencias(l1,5);
  Lista nMenores = obtenerMenores(l1,5);
  cout << cOcurrencias << "\n";
  for (int i = 1; i < nMenores.longLista() + 1; i++)
  {
    printf("%d ", nMenores.infoLista(i));
  }
  return 0;
}
