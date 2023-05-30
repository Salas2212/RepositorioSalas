/*
 * Autor: Juan Esteban Salas
 * Codigo: 8975783
 * Proyecto Final "Big Integer"
 * Archivo: BigInteger.cpp
*/
#include "BigInteger.h"

/*
Función constructora predeterminada
Entrada: Nada.
Salida: Un BigInteger que contiene un solo digito (0).
Descripción: Esta función crea un BigInteger sin que entre algo mas.
Complejidad: O(1)
*/
BigInteger::BigInteger() {
    signo = true;
    numeros.push_back(0);
}
/*
Función constructora con cadena
Entrada: Una cadena de numeros.
Salida: Un BigInteger con los numeros de esa cadena.
Descripción: Esta función crea un BigInteger a partir de una cadena.
Complejidad: O(n) (n siendo la longitud de la cadena que recibe)
*/
BigInteger::BigInteger(const string& cadena) {
    if (cadena[0] == '-') {
        signo = false;
        cadena.substr(1);
    } else {
        signo = true;
    }
    for (int i = cadena.length() - 1; i >= 0; i--) {
        int digit = cadena[i] - '0';
        numeros.push_back(digit);
    }
}

/*
Función constructora con BigInteger
Entrada: Un BigInteger.
Salida: Un BigInteger creado a partir de otro BigInteger.
Descripción: Esta función crea un BigInteger a partir de otro BigInteger, sirve para crear copias de un BigInteger.
Complejidad: O(1)
*/
BigInteger::BigInteger(const BigInteger& B) {
    numeros = B.numeros;
    signo = B.signo;
}

/*
Función add
Entrada: Un objeto BigInteger.
Salida: El resultado de la suma del BigInteger original mas el que entra.
Descripción: Esta función hace la operacion de suma entre dos BigIntegers, modifica solo el BigInteger al que se le hace la operacion.
Complejidad: O(n) (Siendo n el tamaño maximo de los dos numeros, ej: 28734 y 12. n = 5)
*/
void BigInteger::add(BigInteger& N) {
    if(signo != N.signo){
        substract(N);
    }else{
        int maxLength = max(numeros.size(), N.numeros.size());
        numeros.resize(maxLength, 0);
        int residuo = 0;
        for (int i = 0; i < maxLength; i++) {
            int sum = residuo;
            if (i < numeros.size()) {
                sum += numeros[i];
            }
            if (i < N.numeros.size()) {
                sum += N.numeros[i];
            }
            numeros[i] = sum % 10;
            residuo = sum / 10;
        }
        if (residuo > 0) {
            numeros.push_back(residuo);
        }
        if (signo != N.signo) {
            signo = false;
        }
        else if(signo == N.signo){
            signo = true;
        }
        
    }
}

/*
Función product
Entrada: Un objeto BigInteger.
Salida: El resultado de la multiplicacion del BigInteger original con el que entra.
Descripción: Esta función hace la operacion de multiplicacion entre dos BigIntegers, modifica solo el BigInteger al que se le hace la operacion.
Complejidad: O(m+p) Siendo m y p el tamaño de cada numero o longitud.
*/
void BigInteger::product(BigInteger& N) {
    int m = numeros.size();
    int p = N.numeros.size();
    vector<int> resultado(m + p, 0);
    for (int i = 0; i < m; i++) {
        int residuo = 0;
        for (int j = 0; j < p || residuo > 0; j++) {
            int multiplicacion = resultado[i + j] + numeros[i] * 0;
            if (j < p) {
                multiplicacion += numeros[i] * N.numeros[j];
            }
            multiplicacion += residuo;
            resultado[i + j] = multiplicacion % 10;
            residuo = multiplicacion / 10;
        }
    }
    while (resultado.size() > 1 && resultado.back() == 0) {
        resultado.pop_back();
    }
    numeros = resultado;
    if (!N.signo && !signo) {
        signo = true;
    }
    else{
        if(!signo){
            signo = false;
        }
        if(!N.signo){
            signo = false;
        }
    }
}

/*
Función substract
Entrada: Un objeto BigInteger.
Salida: El resultado de la resta del BigInteger original menos el que entra.
Descripción: Esta función hace la operacion de resta entre dos BigIntegers, modifica solo el BigInteger al que se le hace la operacion.
Complejidad: O(n) (Siendo n el tamaño maximo de los dos numeros, ej: 28734 y 12. n = 5)
*/
void BigInteger::substract(BigInteger& N){
    if(!signo && !N.signo){
        add(N);
    }
    else{
        int maxLength = max(numeros.size(), N.numeros.size());
        numeros.resize(maxLength, 0);
        int carry = 0;
        if(numeros.size() < N.numeros.size()){
            for (int i = 0; i < maxLength; i++) {
                int sub = carry;
                if (i < numeros.size()) {
                    sub -= numeros[i];
                }
                if (i < N.numeros.size()) {
                    sub += N.numeros[i];
                }
                if (sub < 0) {
                    sub += 10;
                    carry = -1;
                } else {
                    carry = 0;
                }
                numeros[i] = sub;
            }
            signo = false;
        }
        else{
            for (int i = 0; i < maxLength; i++) {
                int sub = carry;
                if (i < numeros.size()) {
                    sub += numeros[i];
                }
                if (i < N.numeros.size()) {
                    sub -= N.numeros[i];
                }
                if (sub < 0) {
                    sub += 10;
                    carry = -1;
                } else {
                    carry = 0;
                }
                numeros[i] = sub;
            }
            
        }
        while (numeros.size() > 1 && numeros.back() == 0) {
            numeros.pop_back();
        }

    }
} 

/*
Función quotient
Entrada: Un objeto BigInteger.
Salida: El resultado de la division del BigInteger original con el que entra.
Descripción: Esta función hace la operacion de division entre dos BigIntegers, modifica solo el BigInteger al que se le hace la operacion.
*/
void BigInteger::quotient(BigInteger& N) {
    BigInteger divisor;
    divisor = N.abs();
    BigInteger dividend(*this);
    dividend = dividend.abs();
    BigInteger quotient; 
    if (divisor == quotient) {
        cout << "Error: No se pudo hacer la divison ya que el divisor debe ser diferente de 0" << endl;
    }
    else if (dividend == quotient) {
        *this = quotient;
    }
    else{
        string one = "1";
        BigInteger bOne(one);
        while (divisor <= dividend) {
            dividend = dividend - divisor;
            quotient = quotient + bOne;
        }
        quotient = quotient + bOne;
        *this = quotient;
    }
    if (!N.signo && !signo) {
        signo = true;
    }
    else{
        if(!signo){
            signo = false;
        }
        if(!N.signo){
            signo = false;
        }
    }
    
}

/*
Función remainder
Entrada: Un objeto BigInteger.
Salida: El residuo de la division de dos BigIntegers.
Descripción: Esta función hace la operacion de division entre dos BigIntegers para conseguir el residuo, modifica solo el BigInteger al que se le hace la operacion.
*/
void BigInteger::remainder(BigInteger& N) {
    BigInteger bZero;
    BigInteger dividend(*this);
    dividend = dividend.abs();
    BigInteger divisor;
    divisor = N.abs();
    if (divisor == bZero) {
        cout << "Error: No se pudo hacer la divison ya que el divisor debe ser diferente de 0" << endl;
    }
    else if(dividend == bZero){
        *this = bZero;
    }
    else{
        while (divisor <= dividend) {
            dividend.substract(divisor);
        }
    }
    if (!N.signo && !signo) {
        signo = true;
    }
    else{
        if(!signo){
            signo = false;
        }
        if(!N.signo){
            signo = false;
        }
    }
    *this = dividend;
}

/*
Función pow
Entrada: Un entero.
Salida: El resultado de un BigInteger elevado a un entero.
Descripción: Esta función eleva un BigInteger a un numero entero, modifica solo el BigInteger al que se le hace la operacion.
Complejidad: O(log e)
*/
void BigInteger::pow(int& e) {
    string one = "1";
    BigInteger result(one);
    if (e == 0) {
        *this = one;
    }
    else if(e < 0){
        cout << "Error: Este programa no admite exponentes negativos" << endl;
    }
    else{
        while (e > 0) {
            if (e % 2 == 1) {
                result.product(*this);
            }
            else if(e % 2 == 0){
                signo = true;
            }
            *this = *this * *this;
            e /= 2;
        }
    }
    *this = result;
}

/*
Función toString
Entrada: Nada.
Salida: Retorna un string con el contenido del BigInteger.
Descripción: Esta función eleva un BigInteger a un numero entero, modifica solo el BigInteger al que se le hace la operacion.
Complejidad: O(n)
*/
string BigInteger::toString(){
    string result;
    if (numeros.size() == 1 && numeros[0] == 0) {
        result = "0";
    } else {
        if (!signo) {
            result += "-";
        }
        for (int i = numeros.size() - 1; i >= 0; i--) {
            result += to_string(numeros[i]);
        }
    }
    return result;
}

/*
Sobrecarga operador +
Entrada: Un objeto BigInteger.
Salida: Retorna un BigInteger el cual es el resultado de una suma entre dos BigIntegers.
Descripción: Esta sobrecarga utiliza la funcion add para hacer la suma con el operador +.
Complejidad: O(n)
*/
BigInteger BigInteger::operator+(BigInteger& N) {
    BigInteger resultado;
    resultado.numeros = numeros;
    resultado.add(N);
    return resultado;
}

/*
Sobrecarga operador *
Entrada: Un objeto BigInteger.
Salida: Retorna un BigInteger el cual es el resultado de una multiplicación entre dos BigIntegers.
Descripción: Esta sobrecarga utiliza la funcion product para hacer la multiplicación con el operador *.
Complejidad: O(m+p)
*/
BigInteger BigInteger::operator*(BigInteger& N) {
    BigInteger resultado;
    resultado.numeros = numeros;
    resultado.product(N);
    return resultado;
}

/*
Sobrecarga operador -
Entrada: Un objeto BigInteger.
Salida: Retorna un BigInteger el cual es el resultado de una resta entre dos BigIntegers.
Descripción: Esta sobrecarga utiliza la funcion substract para hacer la resta con el operador -.
Complejidad: O(n)
*/
BigInteger BigInteger::operator-(BigInteger& N){
    BigInteger resultado;
    resultado.numeros = numeros;
    resultado.substract(N);
    return resultado;
}

/*
Sobrecarga operador /
Entrada: Un objeto BigInteger.
Salida: Retorna un BigInteger el cual es el resultado de una division entre dos BigIntegers.
Descripción: Esta sobrecarga utiliza la funcion quotient para obtener el resultado con el operador /.
*/
BigInteger BigInteger::operator/(BigInteger& N){
    BigInteger resultado;
    resultado.numeros = numeros;
    resultado.quotient(N);
    return resultado;
}

/*
Sobrecarga operador %
Entrada: Un objeto BigInteger.
Salida: Retorna un BigInteger el cual es el residuo de una division entre dos BigIntegers.
Descripción: Esta sobrecarga utiliza la funcion remainder para obtener el residuo con el operador %.
*/
BigInteger BigInteger::operator%(BigInteger& N){
    BigInteger resultado;
    resultado.numeros = numeros;
    resultado.remainder(N);
    return resultado;
}
/*
Sobrecarga operador <=
Entrada: Un objeto BigInteger.
Salida: Retorna un booleano el cual es la comparacion <= (Menor ó Igual que) entre dos BigIntegers.
Descripción: Esta sobrecarga hace la comparacion entre dos BigIntegers para saber si uno es menor o igual a otro usando el operador <=.
Complejidad: O(2n)
*/
bool BigInteger::operator<=(BigInteger& N){
    bool res = false;
    if((*this < N) || (*this == N)){
        res = true;
    }
    return res;
}

/*
Sobrecarga operador ==
Entrada: Un objeto BigInteger.
Salida: Retorna un booleano el cual es la comparacion == (Igual a) entre dos BigIntegers.
Descripción: Esta sobrecarga hace la comparacion entre dos BigIntegers para saber si uno es igual a otro usando el operador ==.
Complejidad: O(n)
*/
bool BigInteger::operator==(BigInteger& N){
    bool res = true;
    if (numeros.size() != N.numeros.size()) {
        res = false;
    }
    else{
        for (int i = numeros.size() - 1; i >= 0; i--) {
            if (numeros[i] != N.numeros[i]) {
                res = false;
            }
        }
    }
    return res;
}

/*
Sobrecarga operador <
Entrada: Un objeto BigInteger.
Salida: Retorna un booleano el cual es la comparacion < (Menor que) entre dos BigIntegers.
Descripción: Esta sobrecarga hace la comparacion entre dos BigIntegers para saber si uno es menor a otro usando el operador <.
Complejidad: O(n)
*/
bool BigInteger::operator<(BigInteger& N){
    bool res = false;
    if(!signo && N.signo){
        
        res = true;
    }
    else if (numeros.size() < N.numeros.size()) {
        res = true;
    }
    else if(numeros.size() == N.numeros.size()){
        for (int i = numeros.size() - 1; i >= 0; i--) {
            if (numeros[i] != N.numeros[i]) {
                if(numeros[i] < N.numeros[i]){
                    res = true;
                    i = 0;
                }
                else if(numeros[i] > N.numeros[i]){
                    res = false;
                    i = 0;
                }
            }
        }
    }
    return res;
}


/*
Función auxiliar abs
Entrada: Nada.
Salida: El valor absoluto de un BigInteger.
Descripción: Esta función convierte un BigInteger en su forma de valor absoluto (Positivo).
Complejidad: O(1)
*/
BigInteger BigInteger::abs(){
    BigInteger result(*this);
    result.signo = true;
    return result;
}

/*
Función auxiliar tam
Entrada: Nada.
Salida: El tamaño del numero.
Descripción: Esta función retorna el tamaño del vector que guarda los numeros.
Complejidad: O(n)
*/
int BigInteger::tam(){
    return numeros.size();
}

/*
Función estatica sumarListaValores
Entrada: Lista que contiene BigIntegers.
Salida: La suma acumulada de la lista.
Descripción: Esta función retorna un BigInteger que representa la suma acumulada de toda la lista.
Complejidad: O(n^2)
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger>& lista) {
    BigInteger resultado;
    for (list<BigInteger>::iterator it = lista.begin(); it != lista.end(); ++it) {
        resultado.add(*it);
    }
    return resultado;
}

/*
Función estatica multiplicarListaValores
Entrada: Lista que contiene BigIntegers.
Salida: La multiplicacion acumulada de la lista.
Descripción: Esta función retorna un BigInteger que representa la multiplicacion acumulada de toda la lista.
Complejidad: O(n^2)
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& lista) {
    string one = "1";
    BigInteger resultado(one);
    for (list<BigInteger>::iterator it = lista.begin(); it != lista.end(); ++it) {
        resultado.product(*it);
    }
    return resultado;
}

