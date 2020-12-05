#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

typedef struct list{ int data; struct list *next;} list;

// create a list of 100 numbers

list *create(void)
{
    int i;
    list *head = NULL;
    for (i= 0; i< SIZE; i++)
    {
        list *temp_head = head;         // you say that head is the first link
        head = malloc(sizeof(list));
        head -> data = rand()% 1000;
        head -> next = temp_head;
    }
}

// swap elements
void bubblesort(list *h)
{
    int i, j, temp;
    for (i= 1; i< SIZE; i++)
    {
        list *temp_h = h;               // you say that head is i-esimo link of the cycle
        for (j= 0; j< SIZE- i; j++)
        {
            list *b = h-> next;         // b is the pointer of list *next
            if (h-> data < b-> data)
                {
                    temp = h-> data;    // h is the pointer of data
                    h-> data = b-> data;
                    b-> data = temp;
                }
            h = h-> next;               // to update h to next h for j-cycle
        }
        h = temp_h;                     // h change for i-cycle !!
    }
}

// print the list in a table of 5 rows
void print_list(list *h, char *title)
{
    printf("\n%s\n", title);
    int i= 0;
    while(h != NULL)
    {
        printf("%-3d\t", h-> data);
		h = h -> next;
        if (++i % 20 == 0)
            printf("\n");
    }
}


int main()
{
	srand(time(NULL));
    list *pointer = create();
    print_list(pointer, "RANDOM LIST\n");
	printf("\n\n");
    bubblesort(pointer);
    print_list(pointer, "SORTED LIST\n");

    return 0;
}
