#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void readData(FILE *, int [], int *);
void printData(int [], int);
void printOut(FILE *);

int main(int argc, char *argv[]) {
    printf("Hi from C!!\n");
    int _length = MAX;
    FILE *_file;
    int _data[MAX] = {};
    _file = fopen("numeros.log", "r");
    readData(_file, _data, &_length);
    printData(_data, _length);
    printf("\n");
    printOut(_file);

    fclose(_file);
    return 0;
}

void readData(FILE *__file, int __note[], int *__lengthNote) {
    *__lengthNote = 0;
    while(fscanf(__file, "%d", &__note[*__lengthNote]) == 1 ) (*__lengthNote)++;
}

void printData(int __data[], int __lengthData) {
    for (int i = 0; i < __lengthData; i++ ) {
        printf("%d\t", __data[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}

void printOut(FILE *__file) {
    int _el; // char _el
    rewind(__file); // apunta al inicio del archivo
    while ((_el = getc(__file)) != EOF) putc(_el, stdout);
}
