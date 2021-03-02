// g++ -o <name> <namefile>.cpp
#include <iostream>

using namespace std; // link to lib

double const milesToKilometers = 1.609;

long long factorial(int);
inline double convert(int miles){ return miles * milesToKilometers; }

int main(void) {
    int miles = 1;
    while (miles != 0) {
        cout << "Input miles or 0 to terminate: ";
        cin >> miles;
        cout << "Miles to Kilometers -> " << convert(miles) << endl;
    }
    cout << "End" << endl << endl;
    cout << "Factorial" << endl;
    for (auto i = 0; i < 16; i++) cout << "Factorial of " << i << " is " << factorial(i) << endl;
}

long long factorial(int number) {
    long long value = 1;
    for (auto i = 1; i <= number; i++) value *= i;
    return value;
}
