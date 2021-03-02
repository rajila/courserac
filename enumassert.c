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
typedef enum choices {left, left_center = 2, right_center, right = 5} choices;
enum myfoods{butter = 2, milk = 5, cheese = 8, eggs};

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

    // test
    printf("\n%d\n", eggs);
    int a = 2, b = 5, c = 8;
    printf("  a && b  = %d \n ",  a && b);
    printf(" b %% a   = %d \n ", b % a );
    printf(" a / b    = %d \n " , a/b);
    printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b);
    printf(" b <= c = %d \n "  , b<= c);
    printf(" !!c = %d \n " , !!c);
    printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6);
    printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
    printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
    printf(" c = ++b = %d \n ",c = ++b);

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
