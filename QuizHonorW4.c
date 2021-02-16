#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct node{
    int number;
    struct node * left;
    struct node * right;
} node;

void readFile(FILE *, int[], int*);
void printArray(int[], int);
node * newNode();
node * initNode(int, node*, node*);
node * createBTREE(int[], int, int);
void printInOrder(node*, char);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("It necessary one argument with filename!!");
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    int elementsFile[MAX];
    int sizeElements = 0;
    readFile(file, elementsFile, &sizeElements); // save numbers from FILE to arrays
    printf(" Elements from FILE\n\t");
    printArray(elementsFile, sizeElements);
    printf("\n\n");
    node *root = createBTREE(elementsFile, 0, sizeElements);
    printf(" Elements from TREE INORDER\n\t");
    printInOrder(root, 'M');
    free(root); // free memory
    return 0;
}

void readFile(FILE *file, int elementsFile[], int *size) {
    fscanf(file, "%d", size); // reading of first element (FILE)
    while (fscanf(file, "%d", elementsFile++) != EOF); // skipped validation for overflow
}

void printArray(int elementsFile[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", *(elementsFile++));
}

node * newNode() {
    return malloc(sizeof(node));
}

node * initNode(int valueNode, node *nodeLeft, node *nodeRight) {
    node *nodeCurrent = newNode();
    nodeCurrent->number = valueNode;
    nodeCurrent->left = nodeLeft;
    nodeCurrent->right = nodeRight;
    return nodeCurrent;
}

node * createBTREE(int elementsFile[], int position, int size) {
    if (position >= size) return NULL;
    else return initNode(*(elementsFile+position),  createBTREE(elementsFile, 2 * position + 1, size),
                                                    createBTREE(elementsFile, 2 * position + 2, size));
}

void printInOrder(node *nodeFather, char singleLabel) {
    if (nodeFather != NULL) {
        printInOrder(nodeFather->left, 'L');
        printf("%c:%d  ", singleLabel, nodeFather->number);
        printInOrder(nodeFather->right, 'R');
    }
}
