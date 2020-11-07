#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */

int main(void)
{
    double interval;
    int i;
    printf("\n\tTable of values for sine & cosine\n");
    for (i = 0; i < 11; i++)
    {
        interval = i/10.0;
        printf("sin( %lf ) = %lf :::: cos( %lf ) = %lf \n", interval, sin(interval), interval, cos(interval));
    }
    printf("\n+++++++\n");
    return 0;
}
