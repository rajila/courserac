#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 100
#define ROW 5

typedef struct list {
    int _data;
    struct list *_next;
} list;

list* initList(int);
void printList(list*, const char*);
list* createNode(int);
list* addNodeToFront(int, list*);

list* swapping(list*, list*, list*);
list* bubble(int, list*);

int main(void) {
    srand(time(NULL)); // For random
    list *_head = initList(ELEMENTS);
    printList(_head, "List not Sorted");
    _head = bubble(ELEMENTS, _head);
    printList(_head, "List Sorted");
}

list* bubble(int __length, list *__head)
{
    list *_nodePrevio;
    list *_nodeHead = NULL;
    int _flag = 0; // Bandera para salir del loop cuando el arreglo se encuentra ordenado
    for (int i = 0; i < __length - 1; i++) {
        _flag = 0;
        _nodeHead = __head;
        _nodePrevio = NULL;
        for (int j = 0; j < __length - i - 1; j++) {
            if (_nodeHead->_data > _nodeHead->_next->_data) {
                _nodeHead = swapping(_nodePrevio, _nodeHead, _nodeHead->_next);
                _flag = 1;
            }
            if (j == 0) __head = _nodeHead; // update head the list
            _nodePrevio = _nodeHead; // saving node prev
            _nodeHead = _nodeHead->_next; // update the head
        }
        if (_flag == 0) break;
    }
    return __head; // return head of list sorted
}

// Swapping Node
list* swapping(list *__nodePrev, list *__nodeCurrent, list *__nodeNext)
{
    list *_tmp = __nodeNext->_next;
    if (__nodePrev != NULL ) __nodePrev->_next = __nodeNext; // change pointer of node prev
    __nodeNext->_next = __nodeCurrent;
    __nodeCurrent->_next = _tmp;
    return __nodeNext; // return next node as current node
}

// function for init List
list* initList(int __length) {
    list *_head = createNode((rand() % (ELEMENTS * 2)) + 1); // int from 1 to 200
    for (int i = 1; i < __length; i++) _head = addNodeToFront((rand() % (ELEMENTS * 2)) + 1, _head);
    return _head;
}

// Function on course
void printList(list *__list, const char *__title) {
    int _contador = 0;
    printf(" --------------------------------------------------------------------------------\n");
    printf(" |\t\t\t\t%s\t\t\t\t\t|\n", __title);
    printf(" --------------------------------------------------------------------------------\n");
    while (__list != NULL) {
        if (_contador % (ELEMENTS/ROW) == 0) printf("\n");
        _contador++;
        printf("   %d\t", __list->_data);
        __list = __list->_next; // not change puntero later that finish method
    }
    printf("\n\n\n");
}

// Function on course
list* createNode(int __data) {
    list *_head = malloc(sizeof(list));
    _head->_data = __data;
    _head->_next = NULL;
    return _head;
}

// Function on course
list* addNodeToFront(int __data, list *__node) {
    list *_head = createNode(__data);
    _head->_next = __node;
    return _head;
}
