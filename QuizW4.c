#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int numerator;
    int denominator;
} rational;

void readFile(FILE *, rational [], int *);
double getValueRational(rational);
double addRational(rational, rational);
double multiplyRational(rational, rational);
double subtractRational(rational, rational);
double divideRational(rational, rational);
void getSumaAndAverage(rational [], int, double *, double *);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("It necessary one argument with file'name!!");
        exit(1);
    }

    int sizeElements = 0;
    double sum = 0.0, average = 0.0;
    rational elements[MAX] = {};
    FILE *file = fopen(argv[1], "r+");
    readFile(file, elements, &sizeElements);
    getSumaAndAverage(elements, sizeElements, &sum, &average);
    printf("Suma: %.10f\nAverage: %.10f\n", sum, average);
    fclose(file);

    return 0;
}

void readFile(FILE *__file, rational __data[], int *__length) {
    int n, d, index = 0;
    fscanf(__file, "%d", __length);
    while (fscanf(__file, "%d %d", &n, &d) != EOF) {
        rational element = {n, d};
        __data[index++] = element;
    }
}

double getValueRational(rational __element) {
    if (__element.denominator == 0.0) return 0;
    return __element.numerator*1.0/__element.denominator;
}

double addRational(rational elA, rational elB) {
    return getValueRational(elA) + getValueRational(elB);
}

double multiplyRational(rational elA, rational elB) {
    return getValueRational(elA) * getValueRational(elB);
}

double subtractRational(rational elA, rational elB) {
    return getValueRational(elA) - getValueRational(elB);
}

double divideRational(rational elA, rational elB) {
    if (getValueRational(elB) == 0.0) return 0;
    return getValueRational(elA)/getValueRational(elB);
}

void getSumaAndAverage(rational __elements[], int __length, double *__sum, double *__average) {
    for (int i = 0; i < __length; i++) (*__sum) += getValueRational(__elements[i]);
    *__average = *__sum / __length;
}
