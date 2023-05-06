/*
 * Autor: Juan Esteban Salas
 * Codigo: 8975783
 * Proyecto Final "Big Integer"
 * Archivo: BigInteger.cpp
*/
#include "BigInteger.h"

/*Operacion constructora que recibe una cadena de caracteres*/
BigInteger::BigInteger(string &cadena){
    act = NULL;
    int i = 0, tam = cadena.length();
    while (i != tam)
    {
        Nodo* temp;
        Nodo* nuevo = new Nodo;
        nuevo->dato = cadena[i]-'0';
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        if(act == NULL)act = nuevo;
        else{
            temp = act;
            while(temp->sig != NULL)temp = temp->sig;
            temp->sig = nuevo;
            nuevo->ant = temp;
        }
        i++;
    }
}
BigInteger::BigInteger(BigInteger &B){
    act = NULL;
    Nodo* temp = B.act;
    while (temp != NULL) {
        Nodo* nuevo = new Nodo;
        nuevo->dato = temp->dato;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        if (act == NULL) {
            act = nuevo;
        } else {
            Nodo* temp2 = act;
            while (temp2->sig != NULL) {
                temp2 = temp2->sig;
            }
            temp2->sig = nuevo;
            nuevo->ant = temp2;
        }

        temp = temp->sig;
    }
}


/*Operaciones Matematicas*/
void BigInteger::add(BigInteger& N){}
void BigInteger::product(BigInteger& N){}
void BigInteger::subtract(BigInteger& N){}
void BigInteger::quotient(BigInteger& N){}
void BigInteger::remainder(BigInteger& N){}
void BigInteger::pow(BigInteger& e){}

/*Operacion toString*/
string BigInteger::toString() const{
    string res;
    Nodo* temp = act;
    while (temp != NULL) {
        res += char('0' + temp->dato);
        temp = temp->sig;
    }
    return res;
}

/*Sobrecarga de operadores*/
BigInteger operator+(const BigInteger& N1, const BigInteger& N2){}
BigInteger operator-(const BigInteger& N1, const BigInteger& N2){}
BigInteger operator/(const BigInteger& N1, const BigInteger& N2){}
BigInteger operator*(const BigInteger& N1, const BigInteger& N2){}
BigInteger operator%(const BigInteger& N1, const BigInteger& N2){}
bool operator==(const BigInteger& N1, const BigInteger& N2){}
bool operator<(const BigInteger& N1, const BigInteger& N2){}
bool operator<=(const BigInteger& N1, const BigInteger& N2){}


/*Operaciones estaticas*/
BigInteger BigInteger::sumarListaValores(const vector<BigInteger>& lista){}
BigInteger BigInteger::multiplicarListaValores(const vector<BigInteger>& lista){}

