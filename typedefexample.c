#include <stdio.h>

int main(void) {
    printf("Hi world!!\n");
    typedef int myData;
    myData _flag = 1;
    printf("My data -> %d\n", _flag);

    typedef myData dataCustom;
    dataCustom _numero = 3;
    printf("dataCustom -> %d\n", _numero);

    typedef myData *newData; // *newData es un tipo de dato puntero: int*
    // newData _contador = 1; // Error ya que es una variable puntero
    int _promedio = 100;
    newData _ppromedio = &_promedio;
    printf("Valor de variable puntero -> %d\n", *_ppromedio);
    // Puntero to puntero
    *_ppromedio*=2; // === (*_ppromedio)*=2 === (*_ppromedio) = (*_ppromedio) * 2
    (*_ppromedio)++; // *_ppromedio++ -> Error al sumar el valor en una unidad. Lo que hace es desplazar el puntero en una unidad
    ++*_ppromedio; // ++(*_ppromedio) -> OK al sumar el valor en una unidad.
    newData *_pppromedio = &_ppromedio;
    printf("Valor de variable puntero to puntero -> %d\n", **_pppromedio);

    return 0;
}
