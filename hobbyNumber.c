#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define ROW 9
#define COL 100

typedef enum digits {Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine} digits;

void initArray(char[][COL], int, int);
void printArray(char[][COL], int, int);
void fillArray(char[][COL], int *, digits);
void processNumber(char[][COL], int *, int);
void getLengthData(char *, int *);
void processNumberTxt(char[][COL], int *, char *);

int main(int argc, char *argv[]) {
    char txtNumbers[ROW][COL];
    int positionColDraw = 0;
    int lengthData = 0;
    initArray(txtNumbers, ROW, COL);
    getLengthData(argv[1], &lengthData);
    processNumberTxt(txtNumbers, &positionColDraw, argv[1]);
    printArray(txtNumbers, ROW, positionColDraw);
    return 0;
}

void getLengthData(char *txt, int *lengthTxt) {
    while(*(txt++) != '\0') (*lengthTxt)++;
}

void initArray(char txtNumbers[][COL], int row, int col) {
    for(int r = 0; r < row; r++)
        for(int c = 0; c < col; c++) txtNumbers[r][c] = ' ';
}

void printArray(char txtNumbers[][COL], int row, int col) {
    printf("\n\n");
    for(int r = 0; r < row; r++) {
        printf(" ");
        for(int c = 0; c < col; c++) {
            printf("%c ", txtNumbers[r][c]);
            if((c+1) % WIDTH == 0) printf("  ");
        }
        printf("\n");
    }
    printf("\n\n");
}

void fillArray(char txtNumbers[][COL], int *positionColDraw, digits dig) {
    switch (dig) {
        case Zero:
            for(int row = 0; row < ROW; row++) {
                if(row == 0 || row == ROW - 1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw] = '*';
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        case One:
            for(int row = 0; row < ROW; row++) txtNumbers[row][*positionColDraw+4] = '*';
            break;
        case Two:
            for(int row = 0; row < ROW; row++) {
                if(row == 0 || row == ROW - 1 || row == WIDTH-1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                } else if(row < WIDTH-1){
                    txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw] = '*';
            }
            break;
        case Three:
            for(int row = 0; row < ROW; row++) {
                if(row == 0 || row == ROW - 1 || row == WIDTH-1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        case Four:
            for(int row = 0; row < ROW; row++) {
                if(row == WIDTH-1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                } else if(row < WIDTH-1){
                    txtNumbers[row][*positionColDraw] = '*';
                    txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        case Five:
            for(int row = 0; row < ROW; row++) {
                if(row == 0 || row == ROW - 1 || row == WIDTH-1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                } else if(row < WIDTH-1){
                    txtNumbers[row][*positionColDraw] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        case Six:
            for(int row = 0; row < ROW; row++) {
                if(row == 0 || row == ROW - 1 || row == WIDTH-1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                } else if(row < WIDTH-1){
                    txtNumbers[row][*positionColDraw] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw] = '*';
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        case Seven:
            for(int row = 0; row < ROW; row++) {
                if(row == 0) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        case Eight:
            for(int row = 0; row < ROW; row++) {
                if(row == 0 || row == ROW - 1 || row == WIDTH-1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw] = '*';
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        case Nine:
            for(int row = 0; row < ROW; row++) {
                if(row == 0 || row == ROW - 1 || row == WIDTH-1) {
                    for(int i = *positionColDraw; i < *positionColDraw + WIDTH; i++) txtNumbers[row][i] = '*';
                    continue;
                } else if(row < WIDTH-1){
                    txtNumbers[row][*positionColDraw] = '*';
                    txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
                    continue;
                }
                txtNumbers[row][*positionColDraw+WIDTH-1] = '*';
            }
            break;
        default:
            break;
    }
    *positionColDraw += WIDTH;
}

void processNumber(char txtNumbers[][COL], int *positionColDraw, int numero) {
    while(numero > 0) {
        int tmp = numero % 10;
        fillArray(txtNumbers, positionColDraw, tmp);
        numero /= 10;
    }
}

void processNumberTxt(char txtNumbers[][COL], int *positionColDraw, char *txt) {
    int val = *txt - '0';
    while(*(txt++) != '\0') {
        fillArray(txtNumbers, positionColDraw, val);
        val = *txt - '0';
    }
}
