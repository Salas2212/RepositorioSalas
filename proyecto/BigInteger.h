/*
 * Autor: Juan Esteban Salas
 * Codigo: 8975783
 * Proyecto Final "Big Integer"
 * Archivo: BigInteger.h
*/
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Nodo{
    public:
        int dato;
        Nodo* ant;
        Nodo* sig;
};

class BigInteger{
    private:
        Nodo* act;
    public:

    /*Operaciones Constructoras*/
    BigInteger(string &cadena);
    BigInteger(BigInteger& B);

    /*Operaciones Matematicas*/
    void add(BigInteger& n);
    void product(BigInteger& n);
    void subtract(BigInteger& n);
    void quotient(BigInteger& n);
    void remainder(BigInteger& n);
    void pow(BigInteger& e);

    string toString() const;

    /*Sobrecarga de operadores*/
    friend BigInteger operator+(const BigInteger& N1, const BigInteger& N2);
    friend BigInteger operator-(const BigInteger& N1, const BigInteger& N2);
    friend BigInteger operator/(const BigInteger& N1, const BigInteger& N2);
    friend BigInteger operator*(const BigInteger& N1, const BigInteger& N2);
    friend BigInteger operator%(const BigInteger& N1, const BigInteger& N2);
    friend bool operator==(const BigInteger& N1, const BigInteger& N2);
    friend bool operator<(const BigInteger& N1, const BigInteger& N2);
    friend bool operator<=(const BigInteger& N1, const BigInteger& N2);

    /*Operaciones Estaticas*/
    static BigInteger sumarListaValores(const vector<BigInteger>& lista);
    static BigInteger multiplicarListaValores(const vector<BigInteger>& lista);
};

#endif
