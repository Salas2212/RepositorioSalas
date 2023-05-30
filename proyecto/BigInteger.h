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
#include <list>
#include <sstream>

using namespace std;

class BigInteger {
private:
    vector<int> numeros;
    bool signo; //true = positivo | false = negativo
public:
    /* Operaciones Constructoras */
    BigInteger();
    BigInteger(const string&);
    BigInteger(const BigInteger&);

    /* Operaciones Matematicas */
    void add(BigInteger& N);
    void product(BigInteger& n);
    void substract(BigInteger& n);
    void quotient(BigInteger& n);
    void remainder(BigInteger& n);
    void pow(int& e);

    string toString();

    /* Sobrecarga de operadores */
    BigInteger operator+(BigInteger& N);
    BigInteger operator-(BigInteger& N);
    BigInteger operator/(BigInteger& N);
    BigInteger operator*(BigInteger& N);
    BigInteger operator%(BigInteger& N);
    bool operator==(BigInteger& N);
    bool operator<(BigInteger& N);
    bool operator<=(BigInteger& N);
    /*Operaciones Auxiliares*/
    BigInteger abs();
    int tam();
    /* Operaciones estaticas */
    static BigInteger sumarListaValores(list<BigInteger>& lista);
    static BigInteger multiplicarListaValores(list<BigInteger>& lista);
};

#endif
