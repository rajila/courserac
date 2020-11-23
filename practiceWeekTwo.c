#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONTH 12
#define MAX 10
#define BUSINESS 5
#define PORCMAX 100

typedef enum {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} Month;
typedef struct {
    Month _month;
    int _day;
} Date;

void optionA();
int daysOfMonth(Month);
Month nextMonth(Month);
char* nameMonth(Month);
Date nextDate(Date);
void printDate(Date);

typedef enum {HR, SALES, RESEARCH, SOFTWARE, EXECUTIVE} BusinessD;
typedef struct {
    unsigned int _securityNumber;
    BusinessD _businessD;
    int _annualSalary;
} Employe;

void optionB();
unsigned int getSecurityNumber();
BusinessD getBusinessD();
int getAnnualSalary(BusinessD);
void printEmployes(Employe[]);
void fullListEmployes(Employe[]);
char* nameBusiness(BusinessD);

int main(void) {
    srand(time(NULL)); // For random
    optionA();
    optionB();
    return 0;
}

// Get SecurityNumber random
unsigned int getSecurityNumber() {
    return rand() % (50000-65535+1) + 65535; // 50000 to 65535
}

// Get Business Department random
BusinessD getBusinessD() {
    return rand() % BUSINESS; // 0 to 4
}

int getAnnualSalary(BusinessD __business) {
    int _offset = rand() % PORCMAX + 1; // porcent from 1 to 100 %
    switch(__business) {
        case HR:
            return 45000 + (45000*_offset)/100;
        case SALES:
            return 30000 + (30000*_offset)/100;
        case RESEARCH:
            return 32000 + (32000*_offset)/100;
        case SOFTWARE:
            return 21000 + (21000*_offset)/100;
        case EXECUTIVE:
            return 25000 + (25000*_offset)/100;
        default:
            return 0;
    }
}

// Full List
void fullListEmployes(Employe __data[]) {
    for(int i = 0; i<MAX; i++) {
        Employe _employeData = {getSecurityNumber(), getBusinessD()};
        _employeData._annualSalary = getAnnualSalary(_employeData._businessD);
        __data[i] = _employeData;
    }
}

// Print List
void printEmployes(Employe __data[]) {
    printf("\t\t\t\tEmployees\n");
    printf(" -----------------------------------------------------------------------\n");
    printf("| Security Number\t| Annual Salary\t\t| Business Department\t|\n");
    printf("|-----------------------------------------------------------------------|\n");
    for(int i = 0; i<MAX; i++)
        printf("| %d\t\t\t| %d\t\t\t| %s|\n", __data[i]._securityNumber, __data[i]._annualSalary, nameBusiness(__data[i]._businessD));
    printf(" ----------------------------------------------------------------------- \n");
}

char* nameBusiness(BusinessD __business) {
    switch(__business) {
        case HR:
            return "Human Resources\t";
        case SALES:
            return "Sales\t\t\t";
        case RESEARCH:
            return "Research\t\t";
        case SOFTWARE:
            return "Software\t\t";
        case EXECUTIVE:
            return "Executive\t\t";
        default:
            return "NA";
    }
}

void optionB() {
    Employe _employees[MAX];
    fullListEmployes(_employees);
    printEmployes(_employees);
}

void optionA() {
    Date _dateCurrentOne = {FEB, 28};
    printDate(nextDate(_dateCurrentOne));
    Date _dateCurrentTwo = {MAR, 14};
    printDate(nextDate(_dateCurrentTwo));
    Date _dateCurrentThree = {OCT, 31};
    printDate(nextDate(_dateCurrentThree));
    Date _dateCurrentFour = {DEC, 31};
    printDate(nextDate(_dateCurrentFour));
}

// Get next Date
Date nextDate(Date __dateCurrent) {
    Date _dateNext = {__dateCurrent._month, __dateCurrent._day + 1};
    if (__dateCurrent._day % daysOfMonth(__dateCurrent._month) == 0) { // eval if day is last
        _dateNext._day = 1;
        _dateNext._month = nextMonth(__dateCurrent._month);
    }
    return _dateNext;
}

// Print day
void printDate(Date __dateCurrent) {
    printf("%s %d\n", nameMonth(__dateCurrent._month), __dateCurrent._day);
}

// get Days of month
int daysOfMonth(Month __m) {
    if (__m == JAN || __m == MAR || __m == MAY || __m == JUL || __m == AUG || __m == OCT || __m == DEC)
        return 31;
    else if (__m == APR || __m == JUN || __m == SEP || __m == NOV)
        return 30;
    else if (__m == FEB)
        return 28;
    return 0;
}

char* nameMonth(Month __month) {
    switch(__month) {
        case JAN:
            return "January";
        case FEB:
            return "February";
        case MAR:
            return "March";
        case APR:
            return "April";
        case MAY:
            return "May";
        case JUN:
            return "June";
        case JUL:
            return "July";
        case AUG:
            return "August";
        case SEP:
            return "September";
        case OCT:
            return "October";
        case NOV:
            return "November";
        case DEC:
            return "December";
        default:
            return "NA";
    }
}

// get next month
Month nextMonth(Month __month) {
    return (__month + 1) % MONTH;
}
