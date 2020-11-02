#include <stdio.h>
#include <Math.h>

int main(void)
{
  printf("\n\t**********************************************************\n");
  printf("\t**\t\t\tSINE FUNCTION\t\t\t**");
  printf("\n\t**********************************************************\n");
  printf("Program that can give the sine of a value between 0 and 1 (non inclusive)\n\n");
  printf("Enter value: ");

  double _radianesIn = 0.0, _sinValueOut = 0.0; // Variables Input and Out
  scanf("%lf", &_radianesIn); // reading value
  _sinValueOut = sin(_radianesIn); // give the sine
  printf("\nThe Sine value of %lf is %lf", _radianesIn, _sinValueOut); // print out in console
  return 0;
}
