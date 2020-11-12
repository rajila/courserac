#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// gcc -o <name_exe> enumassert.c
#define NDAYS 7
// MACROS
#define PRINTDATA     for(int _i = 0; _i < NDAYS; _i++) \
                        printf("Macro #%d\n", rand() % NDAYS)

enum day { Domingo, Lunes, Martes, Miercoles, Jueves, Viernes, Sabado };
typedef enum day Day;

void printDay(Day);
Day nextDay(Day);

int main(void) {
    printf("Hi from Enumerations!!\n");
    Day __today = Sabado;
    printDay(0);
    printDay(8);
    printDay(__today);
    printDay(nextDay(__today));
    printDay(nextDay(10));

    srand(time(0));
    // call Macro
    PRINTDATA;

    return 0;
}

void printDay(Day __day) {
    switch(__day) {
        case Domingo:
            printf("Domingo\n");
            break;
        case Lunes:
            printf("Lunes\n");
            break;
        case Martes:
            printf("Martes\n");
            break;
        case Miercoles:
            printf("Miercoles\n");
            break;
        case Jueves:
            printf("Jueves\n");
            break;
        case Viernes:
            printf("Viernes\n");
            break;
        case Sabado:
            printf("Sabado\n");
            break;
        default:
            printf("Error!!\n");
    }
}

Day nextDay(Day __day) {
    return (__day + 1) % NDAYS;
}
