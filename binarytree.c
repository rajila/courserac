#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char _character;
    struct node *_left;
    struct node *_right;
} node;

void inorder(node*);
node* newNode(void);
node* initNode(char, node*, node*);
node* createTree(char[], int, int);

int main (void) {
    char _name[] = {'R', 'o', 'n', 'a', 'l', 'd', 'D', 'a', 'n', 'i', 'e', 'l'};
    node *_root = createTree(_name, 0, sizeof(_name)/sizeof(_name[0]));
    inorder(_root);
    printf("\nNodo root -> %c", _root->_character);
    return 0;
}

void inorder(node *__root) {
    if (__root != NULL) {
        inorder(__root->_left);
        printf("%c ", __root->_character);
        inorder(__root->_right);
    }
}

node* newNode(void) {
    return malloc(sizeof(node));
}

node* initNode(char __element, node *__nodeP, node *__nodeQ) {
    node *_node = newNode();
    _node->_character = __element;
    _node->_left = __nodeP;
    _node->_right = __nodeQ;
    return _node;
}

node* createTree(char __array[], int __position, int __length) {
    if (__position >= __length) return NULL;
    else return initNode(__array[__position],
                        createTree(__array, 2 * __position + 1, __length),
                        createTree(__array, 2 * __position + 2, __length));
}
