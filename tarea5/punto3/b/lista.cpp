#include "lista.h"

Lista::Lista(){
  act = NULL;
}

//Punto b
void Lista::insListaOrdenada(Elemento elem){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo; //O(1)
  nuevo->dato = elem; //O(1)
  nuevo->sig = NULL; //O(1)

  if(act == NULL) //O(1)
    act = nuevo;
  else if(elem < act->dato){ //O(1)
    nuevo->sig = act;
    act = nuevo;
  }
  else{
    tmp = act; //O(1)
    while (tmp->sig != NULL && tmp->sig->dato < elem) //O(n) Se ejecuta n veces ay que recorre todos los elementos
      tmp = tmp->sig; //O(1)
    nuevo->sig = tmp->sig;//O(1)
    tmp->sig = nuevo;//O(1)
    
  }
}
/*
En el mejor de los casos es cuando la lista esta vacia, por lo tanto la complejidad seria O(1).
En el peor de los casos se recorre toda la lista.
Complejidad: O(n)
*/


void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}



