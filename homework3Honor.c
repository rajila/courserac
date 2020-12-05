#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 100
#define ROW 5
#define MAXRANDOM 49

typedef struct list {
    int _data;
    struct list *_next;
    struct list *_prev;
} list;

list* initList(int);
void printList(list*, const char*);
void printL(list*, const char*);
list* createNode(int);
list* addNodeToFront(int, list*);

list* swapping(list*, list*);
list* bubble(int, list*);

list* removeAllDuplicate(list*);
list* removeNode(list*);

int main(void) {
    srand(time(NULL)); // For random
    list *_head = initList(ELEMENTS);
    printList(_head, "\t\t\t\tList not Sorted");
    _head = bubble(ELEMENTS, _head);
    printList(_head, "\t\t\t\tList Sorted");
    _head = removeAllDuplicate(_head);
    printList(_head, "List Sorted & Removes all duplicate data");
}

// Remove the node current
list* removeNode(list *__nodeCurrent) {
    list *_nodeNext = __nodeCurrent->_next;
    _nodeNext->_prev = NULL;
    if (__nodeCurrent->_prev != NULL) {
        __nodeCurrent->_prev->_next = _nodeNext;
        _nodeNext->_prev = __nodeCurrent->_prev;
    }
    free(__nodeCurrent);
    return _nodeNext;
}

// Remove all duplicate data
list* removeAllDuplicate(list *__head) {
    list *_tmpHead = __head;
    int _flag = 0; // Flag for get Head main
    while (__head != NULL) {
        if (__head->_next != NULL && __head->_data == __head->_next->_data) {
            __head = removeNode(__head);
        } else {
            if (!_flag++) _tmpHead = __head; // Only change one time
            __head = __head->_next; // not change puntero later that finish method
        }
    }
    return _tmpHead;
}

list* bubble(int __length, list *__head)
{
    list *_nodeHead = NULL;
    int _flag = 0; // Bandera para salir del loop cuando el arreglo se encuentra ordenado
    for (int i = 0; i < __length - 1; i++) {
        _flag = 0;
        _nodeHead = __head;
        for (int j = 0; j < __length - i - 1; j++) {
            if (_nodeHead->_data > _nodeHead->_next->_data) {
                _nodeHead = swapping(_nodeHead, _nodeHead->_next);
                _flag = 1;
            }
            if (j == 0) __head = _nodeHead; // update head the list
            _nodeHead = _nodeHead->_next; // update the head
        }
        if (_flag == 0) break;
    }
    return __head; // return head of list sorted
}

// Swapping Node
list* swapping(list *__nodeCurrent, list *__nodeNext)
{
    list *_tmpNext = __nodeNext->_next;
    list *_tmpPrevCurrent = __nodeCurrent->_prev;
    if (_tmpPrevCurrent != NULL ) _tmpPrevCurrent->_next = __nodeNext; // change pointer of node prev
    if (_tmpNext != NULL ) _tmpNext->_prev = __nodeCurrent; // change pointer of node prev
    __nodeNext->_next = __nodeCurrent;
    __nodeNext->_prev = _tmpPrevCurrent;
    __nodeCurrent->_next = _tmpNext;
    __nodeCurrent->_prev = __nodeNext;

    return __nodeNext; // return next node as current node
}

// function for init List
list* initList(int __length) {
    list *_head = createNode(rand() % MAXRANDOM); // int from 0 to 49
    for (int i = 1; i < __length; i++) _head = addNodeToFront(rand() % MAXRANDOM, _head);
    return _head;
}

// Function on course
void printList(list *__list, const char *__title) {
    int _contador = 0;
    printf(" --------------------------------------------------------------------------------\n");
    printf(" |%s\t\t\t\t\t|\n", __title);
    printf(" --------------------------------------------------------------------------------\n");
    while (__list != NULL) {
        if (_contador % (ELEMENTS/ROW) == 0) printf("\n");
        _contador++;
        printf("   %d\t", __list->_data);
        __list = __list->_next; // not change puntero later that finish method
    }
    printf("\n\n\n");
}

void printL(list *__list, const char *__title) {
    while (__list != NULL) {
        printf("prev -> %p, current -> (%p, %d), next -> %p\n", __list->_prev, __list, __list->_data, __list->_next);
        __list = __list->_next; // not change puntero later that finish method
    }
    printf("\n\n");
}

// Function on course
list* createNode(int __data) {
    list *_head = malloc(sizeof(list));
    _head->_data = __data;
    _head->_next = NULL;
    _head->_prev = NULL;
    return _head;
}

// Function on course
list* addNodeToFront(int __data, list *__node) {
    list *_head = createNode(__data);
    __node->_prev = _head;
    _head->_next = __node;
    return _head;
}
