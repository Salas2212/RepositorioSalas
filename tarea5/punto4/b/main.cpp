
#include "lista.h"
#include <iostream>

using namespace std;


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
  Lista nMenores = l1 + l2;
  for (int i = 1; i < nMenores.longLista() + 1; i++)
  {
    printf("%d ", nMenores.infoLista(i));
  }
  return 0;
}
