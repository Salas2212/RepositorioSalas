
#include "lista.h"
#include <iostream>

using namespace std;


int main(){
  Lista l;
  l.insListaOrdenada(1);
  l.insListaOrdenada(3);
  l.insListaOrdenada(7);
  l.insListaOrdenada(2);
  l.insListaOrdenada(8);
  l.insListaOrdenada(5);

  for (int i = 1; i < l.longLista()+1; i++)
  {
    printf("%d ", l.infoLista(i));
  }
  return 0;
}
