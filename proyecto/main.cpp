/*
 * Autor: Juan Esteban Salas
 * Codigo: 8975783
 * Proyecto Final "Big Integer"
 * Archivo: Main.cpp
*/
#include <iostream>
#include "BigInteger.h"

using namespace std;

int main() {
    string cadena = "873253294434";
    BigInteger bInteger1(cadena);
    cout << "BigInteger 1: " << bInteger1.toString() << endl;

    BigInteger bInteger2(bInteger1);
    cout << "BigInteger 2: " << bInteger2.toString() << endl;

    return 0;
}