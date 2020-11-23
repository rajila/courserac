#include <stdio.h>

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

void reset(stack *);
char top(const stack *);
int empty(const stack *);
int full(const stack *);
void push(stack *, char);
char pop(stack *);

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
