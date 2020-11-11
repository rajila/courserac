#include <stdio.h>

#define MAX 1500 //Max  Length of array

void fillArray(int *, int []);
double getAverage(int, int []);

int main(void)
{
    int _weightElephants[MAX];
    int _lengthArray = 0;
    fillArray(&_lengthArray, _weightElephants);
    printf("Average weight of elephant = %lf", getAverage(_lengthArray, _weightElephants));
    int a = 1, b = 2, c = 3;
    printf("\n%d", a-b*c);
    return 0;
}

/**
 * Get average of array
 */
double getAverage(int __length, int __weightElephants[])
{
    int _suma = 0; // variable
    for(int i=0; i<__length; i++) _suma += __weightElephants[i];
    return (double)_suma/__length;
}

/**
 * Fill the Array with elements of file
 */
void fillArray(int *__length, int __weightElephants[])
{
    FILE *_file;
	int _valueFile;
    int _count = 0; // count elements of file

    _file = fopen("elephant_seal_data.txt", "r"); // open file
	if (_file == NULL) return;

	while (fscanf(_file,"%d", &_valueFile) != EOF) // read file
    {
        __weightElephants[_count] = _valueFile;
        _count++;
    }
    *__length = _count;

	fclose(_file); // close file
}
