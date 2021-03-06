#include <stdio.h>

extern int _contador = 0;

int suma(int);
int fibonaci(int);
char functionA(char);
char functionB(char);
int testFunction(char, char);

void functionTest(void)
{
    static int _called = 0; // Variable que solo se inicia en la primera llamada
    printf("_called value: %d\n", _called);
    _contador += ++_called;
}

int main(void)
{
    int _i = 1;
    int _sum = 0;
    const int _limit = 10;
    for(; _i < _limit; _i++)
    {
        printf(" _i local: %d ::: _contador global: %d\n", _i, _contador);
        functionTest();
    }
    _sum += suma(_limit);
    printf("Suma: %d\n\n", _sum);
    for(_i=0; _i<10;_i++) printf("fibonaci(%d) = %d\n", _i, fibonaci(_i));

    int sumF = testFunction(functionA('A'), functionB('B')); // Primero se ejecuta la funcionB. Derecha a Izquierda <-
    return 0;
}

int suma(int __value)
{
    if( __value == 0 ) return 0;
    else return __value + suma(--__value);
}


int fibonaci(int __index)
{
    if (__index <= 1) return __index;
    else return fibonaci(__index-1) + fibonaci(__index-2);
}

char functionA(char singleChar) {
    printf("%c\n", singleChar);
    return singleChar;
}

char functionB(char singleChar) {
    printf("%c\n", singleChar);
    return singleChar;
}

int testFunction(char charA, char charB) {
    return charA + charB;
}
