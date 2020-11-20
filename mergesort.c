#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void merge(int [], int [], int [], int);
void mergecustom(int [], int [], int, int, int);
void printArray(int [], int, char *);
void printArrayRange(int [], int, int, char *);
void mergesort(int [], int);
void sort(int [], int);
void sortR(int [], int [], int, int, char *, char);
void fillArray(int [], int);

int main(void) {
    srand(time(NULL));
    // int _arrayInitA[] = {69, 77 , 83, 100, 104, 90, 98, 111, 120};
    // printArray(_arrayInitA, 5, "Array A");
    // printArray(_arrayInitA + 5, 4, "Array B");
    // int _arrayAuxA[9] = {0};
    // mergecustom(_arrayInitA, _arrayAuxA, 0, (9-1)/2, 9-1);
    // printArray(_arrayInitA, sizeof(_arrayInitA)/sizeof(_arrayInitA[0]), "Array Sorted");

    int _arrayInitB[] = {83, 70, 121, 98, 122};
    sort(_arrayInitB, sizeof(_arrayInitB)/sizeof(_arrayInitB[0]));

    // int _arrayInitC[] = {98, 72, 109, 100};
    // sort(_arrayInitC, sizeof(_arrayInitC)/sizeof(_arrayInitC[0]));
    //
    // int _arrayInitD[15];
    // fillArray(_arrayInitD, sizeof(_arrayInitD)/sizeof(_arrayInitD[0]));
    // sort(_arrayInitD, sizeof(_arrayInitD)/sizeof(_arrayInitD[0]));
    //
    int _arrayE[] = {'M', 'E', 'R', 'G', 'E', 'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    sort(_arrayE, sizeof(_arrayE)/sizeof(_arrayE[0]));

    return 0;
}

void fillArray(int __array[], int __length) {
    int _cont = 0;
    while (_cont < __length) {
        int _val = rand() % (122-65+1) + 65; // 65 to 122
        if( _val<91 || _val>96) __array[_cont++] = _val;
    }
}

void printArray(int __dataArray[], int __length, char *__title) {
    printf(" %s\n ", __title);
    for(int _i=0; _i < 2*__length; _i++) printf("----");
    printf("\n |");
    for(int _i=0; _i < __length; _i++) printf("  %d\t|", _i);
    printf("\n ");
    for(int _i=0; _i < 2*__length; _i++) printf("----");
    printf("\n |");
    for(int _i=0; _i < __length; _i++) printf("  %c\t|", __dataArray[_i]);
    // printf("\n |");
    // for(int _i=0; _i < __length; _i++) printf("  %d\t|", __dataArray[_i]);
    printf("\n ");
    for(int _i=0; _i < 2*__length; _i++) printf("----");
    printf("\n\n");
}

void printArrayRange(int __dataArray[], int __indexStart, int __indexEnd, char *__title) {
    printf(" %s\n ", __title);
    for(int _i=0; _i < 2*(__indexEnd - __indexStart + 1); _i++) printf("----");
    printf("\n |");
    for(int _i=__indexStart; _i < __indexEnd + 1; _i++) printf("  %d\t|", _i);
    printf("\n ");
    for(int _i=0; _i < 2*(__indexEnd - __indexStart + 1); _i++) printf("----");
    printf("\n |");
    for(int _i=__indexStart; _i < __indexEnd+1; _i++) printf("  %d\t|", __dataArray[_i]);
    printf("\n ");
    for(int _i=0; _i < 2*(__indexEnd - __indexStart + 1); _i++) printf("----");
    printf("\n\n");
}

// Both arrays A & B have th same length and sorted. Condition necessary
void merge(int _arrayA[], int _arrayB[], int _arrayResult[], int _lengthArrayAorB) {
    int _pivoteA = 0;
    int _pivoteB = 0;
    int _pivoteResult = 0;
    while (_pivoteA < _lengthArrayAorB && _pivoteB < _lengthArrayAorB) {
        if (_arrayA[_pivoteA] > _arrayB[_pivoteB]) _arrayResult[_pivoteResult++] = _arrayB[_pivoteB++];
        else _arrayResult[_pivoteResult++] = _arrayA[_pivoteA++];
    }
    while(_pivoteA < _lengthArrayAorB) _arrayResult[_pivoteResult++] = _arrayA[_pivoteA++];
    while(_pivoteB < _lengthArrayAorB) _arrayResult[_pivoteResult++] = _arrayB[_pivoteB++];
}

void mergecustom(int __arrayInit[], int __arrayAux[], int __indexStart, int __indexMiddle, int __indexEnd) {
    int _pivoteA = __indexStart;
    int _pivoteB = __indexMiddle + 1;
    int _pivoteInit = __indexStart;
    // printArrayRange(__arrayAux, __indexStart, __indexEnd, "\n Before");

    // SOLO CAS0 I
    for (int i=__indexStart; i<=__indexEnd; i++) __arrayAux[i] = __arrayInit[i];
    while (_pivoteA < __indexMiddle + 1  && _pivoteB < __indexEnd + 1) {
        if (__arrayAux[_pivoteA] > __arrayAux[_pivoteB]) __arrayInit[_pivoteInit++] = __arrayAux[_pivoteB++];
        else __arrayInit[_pivoteInit++] = __arrayAux[_pivoteA++];
    }
    while(_pivoteA < __indexMiddle + 1) __arrayInit[_pivoteInit++] = __arrayAux[_pivoteA++];
    while(_pivoteB < __indexEnd + 1) __arrayInit[_pivoteInit++] = __arrayAux[_pivoteB++];
    // FIN CASO I
    // printArrayRange(__arrayAux, __indexStart, __indexEnd, "\n After");
}

void sortR(int __arrayNS[], int __arrayAux[], int __indexStart, int __indexEnd, char *__ttile, char __access) {
    static char _access = 'a';
    int _middle = __indexStart + (__indexEnd - __indexStart) / 2;
    if (__indexEnd <= __indexStart) {
        printf(" %c) %s & RETURN\t-> (Io=%d, If=%d, m=%d)\n", _access++, __ttile, __indexStart, __indexEnd, _middle);
        return;
    }
    printf(" %c) %s\t\t-> (Io=%d, If=%d, m=%d)\n", _access++, __ttile, __indexStart, __indexEnd, _middle);

    // CASO I
    sortR(__arrayNS, __arrayAux, __indexStart, _middle, "SortA", __access);
    sortR(__arrayNS, __arrayAux, _middle + 1, __indexEnd, "SortB", __access);
    // FIN CASO I

    if (__arrayNS[_middle + 1] >= __arrayNS[_middle]) {
        printf(" %c) %s\t-> (Io=%d, If=%d, m=%d)\n", _access++, "NOT MERGE & RETURN", __indexStart, __indexEnd, _middle);
        return;
    }
    printf(" %c) %s\t\t-> (Io=%d, If=%d, m=%d)\n", _access++, "MERGE", __indexStart, __indexEnd, _middle);
    mergecustom(__arrayNS, __arrayAux, __indexStart, _middle, __indexEnd);
}

void sort(int __arrayNS[], int __length) {
    int _arrayAux[__length];
    printArray(__arrayNS, __length, "Array Not Sorted");
    sortR(__arrayNS, _arrayAux, 0, __length-1, "START", 'a');
    printArray(__arrayNS, __length, "\n Array Sorted");
}

// Only vectors of: 2..4..8..16..32..etc
void mergesort(int __arrayInit[], int __lengthInit) {
    int _pasada;
    int _pivote;
    int _result[__lengthInit];
    int i;
    char _title[100];
    for (_pasada = 1; _pasada < __lengthInit; _pasada *= 2) {
        sprintf(_title, "Pasada #%d", _pasada);
        assert(_pasada>0);
        for (_pivote = 0; _pivote < __lengthInit - _pasada; _pivote += _pasada * 2) {
            merge(__arrayInit+_pivote, __arrayInit+_pivote+_pasada, _result+_pivote, _pasada);
            sprintf(_title, "Pasada #%d.%d", _pasada, _pivote);
            printArray(_result, __lengthInit, _title);
        }
        for (_pivote = 0; _pivote < __lengthInit; _pivote++) __arrayInit[_pivote] = _result[_pivote];
        sprintf(_title, "Fin pasada #%d", _pasada);
        printArray(_result, __lengthInit, _title);
    }
}
