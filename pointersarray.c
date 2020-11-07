#include <stdio.h>

double averageNotes(int, double []);
void swapping(int *, int *);
void bubble(int, int []);
void sortBySwapping(int, int []);
void printArray(int, int []);
void printArrayM(int, int [], int, int);
void bubbleCourse(int [], int);

int main(void)
{
    int _notesA[5];
    printf("Dim bytes _notesA -> %d\n", sizeof(_notesA));
    printf("Dim elements _notesA  -> %d\n", sizeof(_notesA) / sizeof(_notesA[0]));
    printf("Element of _notesA -> %d\n\n", _notesA[3]); // The value is random. You should inicializa el array.

    int _notesB[5] = {1,2,3,4,5};
    int _notesC[5] = {0}; // init all elements to zero
    int _notesD[] = {1,2,3}; //Not element '\0'
    printf("Dim bytes _notesD -> %d\n", sizeof(_notesD));
    printf("Dim elements _notesD  -> %d\n", sizeof(_notesD) / sizeof(_notesD[0]));

    char _nameA[] = "a b c"; // Six elements, include '\0' last element
    printf("Dim _nameA  -> %d\n", sizeof(_nameA) / sizeof(_nameA[0]));
    for(int i = 0; i < sizeof(_nameA) / sizeof(_nameA[0]); i++) printf("Value -> %c, %d\n", _nameA[i], _nameA[i]);

    // Pointers
    int _numFruits = 45;
    int *_pnumFruits = NULL;
    if (_pnumFruits == NULL) _pnumFruits = &_numFruits;
    printf("Address Fruits -> %p\n", _pnumFruits); // Address en Hexadecimal
    printf("Address Fruits -> %lu\n", _pnumFruits); // Address en binario
    printf("Value Fruits --> %d\n", *_pnumFruits); // Value of variable 45

    double _notes[] = {84.87, 98.43, 100.89, 55.89, 45.98};
    printf("Average -> %lf\n", averageNotes(sizeof(_notes)/sizeof(_notes[0]), _notes) );

    int _start = 20;
    int _end = 40;
    printf("(%d, %d)\n", _start, _end);
    swapping(&_start, &_end);
    printf("(%d, %d)\n", _start, _end);

    int _courses[] = {4, 2, 8, 8, 4, 1, 76, 34, 98};
    printArray(sizeof(_courses)/sizeof(_courses[0]), _courses);
    printf("\n");
    bubble(sizeof(_courses)/sizeof(_courses[0]), _courses);
    printf("\n\n");
    // int _coursesCoursera[] = {4, 2, 8, 8, 4, 1, 76, 34, 98};
    int _coursesCoursera[] = {98, 34, 76, 1, 4, 8, 8, 2, 4};
    bubbleCourse(_coursesCoursera, sizeof(_coursesCoursera)/sizeof(_coursesCoursera[0]));

    int _coursesCourseraA[] = {4, 2, 8, 8, 4, 1, 76, 34, 98};
    bubbleCourse(_coursesCourseraA, sizeof(_coursesCourseraA)/sizeof(_coursesCourseraA[0]));

    return 0;
}

void bubble(int __length, int __arreglo[])
{
    int _flag = 0; // Bandera para salir del loop cuando el arreglo se encuentra ordenado
    for(int i=0; i<__length-1; i++)
    {
        _flag = 0;
        printf("-- Pasada #%d --\n", i);
        printArray(__length, __arreglo);
        printf("\n");
        for(int j=0; j<__length-i-1;j++)
        {
            if(__arreglo[j] > __arreglo[j+1])
            {
                swapping(&__arreglo[j], &__arreglo[j+1]);
                printf(">> ");
                printArrayM(__length, __arreglo, j, j+1);
                printf("\n");
                _flag = 1;
            }
        }
        printArray(__length, __arreglo);
        printf("\n\n");
        if(_flag==0) break;
    }
}

void sortBySwapping(int __length, int __arreglo[])
{
    for(int i=0; i<__length-1; i++)
    {
        printf("-- Pasada #%d --\n", i);
        printArray(__length, __arreglo);
        printf("\n");
        for(int j=i+1; j<__length;j++)
        {
            if(__arreglo[i] > __arreglo[j])
            {
                swapping(&__arreglo[i], &__arreglo[j]);
                printf(">> ");
                printArrayM(__length, __arreglo, i, j);
                printf("\n");
            }
        }
        printArray(__length, __arreglo);
        printf("\n\n");
    }
}

double averageNotes(int __lengthS, double __notesStudents [])
{
    double _suma = 0.0;
    printf("#Students -> %d\n", __lengthS);
    for(int i=0; i < __lengthS; i++ ) _suma += __notesStudents[i];
    return _suma/__lengthS;
}

void swapping(int *__a, int *__b)
{
    int _tmp = *__a;
    *__a = *__b;
    *__b = _tmp;
}

void printArray(int __length, int __arreglo[])
{
    for(int i=0; i<__length; i++) printf("%d  ", __arreglo[i]);
}

void printArrayM(int __length, int __arreglo[], int __indexA, int __indexB)
{
    for(int i=0; i<__length; i++) (__indexA == i || __indexB == i )? printf("|%d| ", __arreglo[i]):printf("%d  ", __arreglo[i]);
}

void bubbleCourse(int __data[], int __howMany)
{
    for(int i=0; i<__howMany; i++)
    {
        printf("-- Pasada #%d --\n", i);
        printArray(__howMany, __data);
        printf("\n");
        for(int j=__howMany-1; j>i;j--)
        {
            if(__data[j-1] > __data[j])
            {
                swapping(&__data[j-1], &__data[j]);
                printf(">> ");
                printArrayM(__howMany, __data, j-1, j);
                printf("\n");
            }
        }
        printArray(__howMany, __data);
        printf("\n\n");
    }
}
