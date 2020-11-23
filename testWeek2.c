//JosÃ© Antonio
//Program to determine the next day based on defined dates due to the assignments
//20/11/2020---CR
#include<stdio.h> //standard in/out library
int max_days_per_month[12]= {31,28,31,30,31,30,31,31,30,31,30,31}; // Define the maximum amount of days per month
typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec} month; //defined enum
typedef struct date { month m; int d; } date;  //defined structure
char *names[]={"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sept", "oct", "nov", "dec"};//define names to be printed as chars

date nextday(date x)//function to calculate next day
{
   date nextdayy; //defining nextdayy
	nextdayy.d = (x.d + 1) % max_days_per_month[x.m]; //getting access to nextdayy value and applying modulo to figure out if the amount of days has been over passed
	if (nextdayy.d < x.d) //comparing nextdayyÂ´s value to the defined value on the assignment
		nextdayy.m = (x.m + 1) % 12;
	else
		nextdayy.m = x.m;
	return nextdayy;
}
void printdate(date x) //function to print results
{
	printf("%s %d; ", names[x.m], x.d); //printing results
}
int main(void)//main code
{
    int j; //Works as a counter for passing through the structures and enum.
    date origin[]=
    {
		{.m = jan,.d = 1}, //set jan and day=1
		{.m = feb,.d = 28}, //set feb and day=28
		{.m = mar,.d = 14}, //set mar and day=14
		{.m = oct,.d = 31}, //set oct and day=31
		{.m = dec,.d = 31}, //set dec and day=31
	};
	date nextdayy;  //code to figure out the next day
	for (j = 0; j < 5; j++)  //j initialized to 0, j compared to accounting of 5 months!!! and j auto-incremented
	{
		nextdayy = nextday(origin[j]); //calling function nextday for every month
		printf("Defined date is: ");
		printdate(origin[j]); //calling printdate for every month
		printf("Next day is: \t");
		printdate(nextdayy);
		printf("\n");
	}
	return 0;
}
