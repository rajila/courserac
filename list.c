#include <stdio.h>
#include <stdlib.h>

typedef struct listC {
    int value;
    struct listC * next;
} listC;

listC * assignMemory();
listC * initList(int);
void addLastElement(int, listC **);
listC * createList(int *, int);
void printList(listC *);
void deleteElementError(listC *, listC **, listC **);
void deleteElement(listC *, listC *, listC **);
void deleteList(listC *);

int main(void) {
    int elements[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(elements)/sizeof(*elements);
    listC * head = createList(elements, size);
    printList(head);
    deleteElement(head, NULL, &head); // 1, null, 1
    printList(head);
    deleteElement(head->next->next, head->next, &head); // 4, 3, 2 -> Delete 4
    printList(head);
    deleteElement(head->next, head, &head);
    printList(head);
    deleteList(head);
    head = NULL;

    return 0;
}

listC * assignMemory() {
    return malloc(sizeof(listC));
}

listC * initList(int value) {
    listC * element = assignMemory();
    element->value = value;
    element->next = NULL;
    return element;
}

void addLastElement(int value, listC **elCurrent) {
    listC * element = initList(value);
    (*elCurrent)->next = element;
    *elCurrent = element;
}

listC * createList(int *elements, int size) {
    listC *head = initList(*elements);
    listC *tmp = head;
    for(int i = 1; i < size; i++) addLastElement(*(elements+i), &tmp);
    return head;
}

void printList(listC *head) {
    while(head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void deleteElementError(listC *elementDel, listC **prevEl, listC **head) {
    if(*head == *prevEl)
        *head = elementDel->next;
    else
        (*prevEl)->next = elementDel->next;
    free(elementDel);
}

void deleteElement(listC *elementDel, listC *prevEl, listC **head) {
    if(*head == elementDel)
        *head = elementDel->next;
    else
        prevEl->next = elementDel->next;
    free(elementDel);
}

void deleteList(listC *head) {
    if(head != NULL) {
        deleteList(head->next);
        free(head);
    }
}
