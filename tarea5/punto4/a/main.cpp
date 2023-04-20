
#include "lista.h"
#include <iostream>

using namespace std;

Lista concatenarListas(Lista &l1, Lista &l2){
  for (int i = 1; i < l2.longLista()+1; i++) //O(n) El ciclo se itera las n veces de su longitud
  {
    l1.anxLista(l2.infoLista(i)); //La funcion anxLista se itera n veces ya que añade un elemento al final || La funcion infoLista se itera 1 vez en el mejor caso y n veces en el peor
  }
  return l1;
}


int main(){
  Lista l1, l2;
  //Elementos Lista 1
  l1.anxLista(5);
  l1.anxLista(5);
  l1.anxLista(4);
  l1.anxLista(6);
  l1.anxLista(5);
  l1.anxLista(3);
  l1.anxLista(2);
  //Elementos Lista 2
  l2.anxLista(6);
  l2.anxLista(3);
  l2.anxLista(2);
  l2.anxLista(9);
  l2.anxLista(5);
  l2.anxLista(1);
  l2.anxLista(8);

  Lista l3 = concatenarListas(l1,l2);
  for (int i = 1; i < l3.longLista()+1; i++)
  {
    printf("%d ", l3.infoLista(i));
  }
  return 0;
}
