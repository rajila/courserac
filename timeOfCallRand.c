#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCALLS 1000
#define NCOLS 7
#define NLINES 7

int main(void)
{
    int i, val;
    long begin, diff, end;

    begin = time(NULL);
    srand(time(NULL));
    printf("\nTIMING TEST: %d calls to rand()\n\n", NCALLS);
    for (i=1; i<=NCALLS; ++i)
    {
        val = rand();
        if (i <= NCOLS * NLINES)
        {
            printf("%7d", val);
            if(i%NCOLS == 0) putchar('\n');
        }else if(i == NCOLS * NLINES +1) printf("%7s\n\n", ".....");
    }
    end = time(NULL);
    diff = end - begin;
    printf("%s%1d\n%s%1d\n%s%1d\n%s%.10f\n\n", "end time: ", end, "begim time: ", begin, "elapsed time: ", diff, "time for each call: ", (double)diff/NCALLS);
    return 0;
}
