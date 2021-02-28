#include <stdio.h>
#include <stdlib.h>

void printValueA(int *, int *); // Only print values
void printValueB(int *, int *); // First change directions of pointers, but only into function
void printValueC(int **, int **);

void printTextA(char *); // NOT change position of pointer
void printTextB(char *); // NOT change position of pointer
void printTextC(char **); // YES change position of pointer
void printTextD(char **); // YES change position of pointer
void printTextE(char **); // YES change position of pointer, but only on function

void printCharA(char *);
void printCharB(char *);
void printCharC(char **);

void printIntA(int[], int);
void printIntB(int[], int);
void printIntC(int[], int);
void printIntD(int*, int);
void printIntE(int*, int);

int main(void) {
    int numA = 10, numB = 20;
    int *pnumA = &numA, *pnumB = &numB;
    printValueA(pnumA, pnumB);
    printValueB(pnumA, pnumB);
    printValueA(pnumA, pnumB);
    printValueC(&pnumA, &pnumB);
    printValueA(pnumA, pnumB);
    printf("\n");

    char *name = "RonaldDaniel";
    printTextA(name);
    printTextB(name);
    printTextA(name);
    printTextC(&name);
    printTextA(name);
    printTextA(name);
    printTextD(&name);
    printTextA(name);
    printTextE(&name);
    printTextA(name);
    printf("\n");

    char surname[] = "RonaldAjila"; // No change position on direction, because a array is constant
    char *pPSurname = surname;
    printCharA(surname);
    printCharB(surname);
    printCharA(surname);
    printCharC(&pPSurname);
    printCharA(pPSurname);
    printCharC(&pPSurname);
    printCharA(pPSurname);
    printf("\n");

    int notes[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printIntA(notes, sizeof(notes)/sizeof(notes[0]));
    printIntB(notes, sizeof(notes)/sizeof(notes[0]));
    printIntC(notes, sizeof(notes)/sizeof(notes[0]));
    printIntD(notes, sizeof(notes)/sizeof(notes[0]));
    printIntE(notes, sizeof(notes)/sizeof(notes[0]));
    printIntA(notes, sizeof(notes)/sizeof(notes[0]));

    return 0;
}

void printValueA(int *pNumA, int *pNumB) {
    printf("numA: %d\tnumB: %d\n", *pNumA, *pNumB);
}

void printValueB(int *pNumA, int *pNumB) {
    int *pTmp = pNumA;
    pNumA = pNumB;
    pNumB = pTmp;
    printf("numA: %d\tnumB: %d\n", *pNumA, *pNumB);
}

void printValueC(int **pNumA, int **pNumB) {
    int *pTmp = *pNumA;
    *pNumA = *pNumB;
    *pNumB = pTmp;
    printf("numA: %d\tnumB: %d\n", **pNumA, **pNumB);
}

void printTextA(char *txt) {
    printf("%s\n", txt);
}

void printTextB(char *txt) {
    printf("%s\n", ++txt);
}

void printTextC(char **txt) {
    printf("%s\n", ++(*txt));
}

void printTextD(char **txt) {
    printf("%s\n", --(*txt));
}

void printTextE(char **txt) {
    printf("%s\n", *txt+1);
}

void printCharA(char *txt) {
    printf("%c\n", txt[0]);
}

void printCharB(char *txt) {
    printf("%c\n", *(txt++));
}

void printCharC(char **txt) {
    printf("%c\n", *((*txt)++));
}

void printIntA(int notes[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", notes[i]);
    printf("\n");
}

void printIntB(int notes[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", *(notes+i)); // No change postion pointer
    printf("\n");
}

void printIntC(int notes[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", *(notes++)); // Yes change position pointer, but only function
    printf("\n");
}

void printIntD(int *notes, int size) {
    for (int i = 0; i < size; i++) printf("%d ", notes[i]);
    printf("\n");
}

void printIntE(int *notes, int size) {
    for (int i = 0; i < size; i++) printf("%d ", *(notes++)); // Yes change position pointer, but only function
    printf("\n");
}
