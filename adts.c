#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define EMPTY -1
#define FULL (MAX + EMPTY)

struct point {
    double _x;
    double _y;
};

typedef struct {
    int _pips;
    char _snit;
} card;

typedef struct {
    char _character[MAX];
    int _top;
} stack;

typedef struct list {
    int _data;
    struct list *_next;
} list;

void reset(stack *);
char top(const stack *);
int empty(const stack *);
int full(const stack *);
void push(stack *, char);
char pop(stack *);

int isEmpty(const list*);
void printList(const list*, const char*);
list* createNode(int);
list* addNodeToFront(int, list*);
list* arrayToList(int[], int);
int countElementsList(list*);
int sumaElements(list*);
void concatList(list*, list*);
list* findNode(list*, int);
void insertNode(list*, list*, list*);

int main (void) {
    printf("Hi from ADT\n");
    struct point _point = {12, 38.5};
    printf("point._x = %.1f\n", _point._x);
    printf("point._y = %.1f\n", _point._y);

    struct point *_pPoint;
    _pPoint = &_point;
    printf("_pPoint->_x = %.1f\n", _pPoint->_x);
    printf("_pPoint->_y = %.1f\n", _pPoint->_y);
    printf("*_pPoint._x = %.1f\n", (*_pPoint)._x);
    printf("*_pPoint._y = %.1f\n", (*_pPoint)._y);
    _pPoint->_x = 12.4*2;
    printf("_pPoint->_x = %.1f\n", _pPoint->_x);
    printf("point._x = %.1f\n", _point._x);
    (*_pPoint)._x = 12.4*3;
    printf("_pPoint->_x = %.1f\n", _pPoint->_x);
    printf("point._x = %.1f\n", _point._x);

    struct point _data;
    struct point *_pdata = &_data; // Init variables of strcut a ZERO
    printf("_pdata->_x = %f\n", _pdata->_x);

    struct point _dataOne = {2.5};
    struct point *_pdataOne = &_dataOne; // Init variables of strcut a ZERO
    printf("_pdataOne->_x = %f\n", _pdataOne->_x);

    struct point _dataTwo = {2.5, _dataTwo._x};
    struct point *_pdataTwo = &_dataTwo; // Init variables of strcut a ZERO
    printf("_pdataTwo->_y = %f\n", _pdataTwo->_y);

    card _deck[52];

    stack _testOne;
    reset(&_testOne);
    printf("%d\n", _testOne._top);
    push(&_testOne, 'R');
    push(&_testOne, 'o');
    push(&_testOne, 'n');
    push(&_testOne, 'a');
    push(&_testOne, 'l');
    push(&_testOne, 'd');
    printf("%d\n", _testOne._top);
    printf("%c\n", top(&_testOne));

    while (!empty(&_testOne)) printf("%c", pop(&_testOne));

    // List ADTS
    list *_head = NULL;
    if (_head == NULL) _head = malloc(sizeof(list)); // assig memory
    printf("\nsizeof(list) -> %lu\n", sizeof(list)); // Memory Space for variable _head
    _head->_data = 1;
    _head->_next = NULL;
    printList(_head, "Single element list");
    free(_head); // free memory

    int _listOne[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list *_headOne = arrayToList(_listOne, sizeof(_listOne)/sizeof(_listOne[0]));
    printList(_headOne, "Array To List One");
    printf("Numero elementos: %d\n", countElementsList(_headOne));
    printf("Sumatoria: %d\n", sumaElements(_headOne));
    int _listTwo[] = {100, 200, 300, 400};
    list *_headTwo = arrayToList(_listTwo, sizeof(_listTwo)/sizeof(_listTwo[0]));
    printList(_headTwo, "Array To List Two");
    // Join List
    concatList(_headOne, _headTwo);
    printList(_headOne, "Join Array One & Two");
    printf("Numero elementos: %d\n", countElementsList(_headOne));
    printf("Sumatoria: %d\n", sumaElements(_headOne));

    // Find Node
    list *_nodeSearchOne = findNode(_headOne, 15);
    if (_nodeSearchOne == NULL) printf("El elemento %d NO EXISTE\n", 15);
    _nodeSearchOne = findNode(_headOne, 7);
    if (_nodeSearchOne == NULL) printf("El elemento %d NO EXISTE\n", 7);
    else printf("El elemento %d SI EXISTE\n", 7);
    // list *_nodeNext = _nodeSearchOne->_next;
    // Insert Node
    insertNode(_nodeSearchOne, _nodeSearchOne->_next, createNode(505));
    char _txt[100];
    sprintf(_txt, "Insert Node %d entre %d y %d", 505, _nodeSearchOne->_data, _nodeSearchOne->_next->_next->_data);
    printList(_headOne, _txt);
    // printList(_headOne, "Insert Node %d entre %d y %d", 505, _nodeSearchOne->_data, _nodeSearchOne->_next->_data);

    return 0;
}

void reset(stack *__data) {
    __data->_top = EMPTY;
}

char top(const stack *__data) {
    return __data->_character[__data->_top];
}

int empty(const stack *__data) {
    return __data->_top == EMPTY;
}

int full(const stack *__data) {
    return __data->_top == FULL;
}

void push(stack *__data, char __element) {
    __data->_character[++__data->_top] = __element;
}

char pop(stack *__data) {
    return __data->_character[__data->_top--];
}

int isEmpty(const list *__list) {
    return __list == NULL;
}

void printList(const list *__list, const char *__title) {
    printf("%s\n", __title);
    while (__list != NULL) {
        printf("%d ", __list->_data);
        __list = __list->_next; // not change puntero later that finish method
    }
    printf("\n");
}

list* findNode(list *__head, int __value) {
    while (__head != NULL) {
        if (__head->_data == __value) return __head;
        __head = __head->_next;
    }
    return NULL;
}

int countElementsList(list *__head) {
    if (__head->_next == NULL) return 1;
    else return 1 + countElementsList(__head->_next);
}

int sumaElements(list *__head) {
    if (__head->_next == NULL) return __head->_data;
    else return __head->_data + sumaElements(__head->_next);
}

void concatList(list *__headOne, list *__headTwo) {
    if (__headOne->_next == NULL) __headOne->_next = __headTwo;
    else concatList(__headOne->_next, __headTwo);
}

void insertNode(list *__nodeP, list *__nodeR, list *__nodeQ) {
    if (__nodeP->_next == __nodeR) {
        __nodeP->_next = __nodeQ;
        __nodeQ->_next = __nodeR;
    }
}

list* createNode(int __data) {
    list *_head = malloc(sizeof(list));
    _head->_data = __data;
    _head->_next = NULL;
    return _head;
}

list* addNodeToFront(int __data, list *__node) {
    list *_head = createNode(__data);
    _head->_next = __node;
    return _head;
}

list* arrayToList(int __array[], int __length) {
    list *_head = createNode(__array[0]);
    for (int i = 1; i < __length; i++) _head = addNodeToFront(__array[i], _head);
    return _head;
}
