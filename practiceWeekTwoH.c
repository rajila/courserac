#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX 1000000
#define SUITS 4
#define HAND 7
#define CARDS 52
#define PIPS 13

typedef enum {Clubs, Diamonds, Hearts, Spades} Suit;
typedef enum {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King} Pips;
typedef struct {
    Suit _suit;
    int _pips;
} Card;

void initDeck(Card[], int);
void printCards(Card[], int, int);
void print(Card[], int);
char nameSuit(Suit);
void shuffle(Card[], int);
void test();
void probabilityCardHand(Card[], int, int, int);
Pips nextPip(Pips);
void countSuitOnHand(int*, int*, int*, int*, Suit);
int isRoyalFlush(Card[], int);
int isStraightFlush(Card[], int);
int isFourOfKind(Card[], int);
int isFullHouse(Card[], int);
int isFlush(Card[], int);
int isStraight(Card[], int);
int isThreeOfKind(Card[], int);
int isTwoPairs(Card[], int);
int isPair(Card[], int);
void sort(Card[], int);

int main(void) {
    srand(time(NULL)); // For random
    Card _deck[CARDS];
    initDeck(_deck, CARDS);
    // test();
    probabilityCardHand(_deck, CARDS, HAND, MAX);
}

void probabilityCardHand(Card __deck[], int __length, int __sets, int __cycles) {
    int _isRoyal, _isStraing, _isFourK, _isFullH, _isFlush, _isStraight, _isThreeOfKind, _isTwoPairs, _isPair, _isAceHighOrLess;
    _isRoyal = _isStraing = _isFourK = _isFullH = _isFlush = _isStraight = _isThreeOfKind = _isTwoPairs = _isPair = _isAceHighOrLess = 0;
    for(int i=0; i<__cycles;i++) {
        shuffle(__deck, __length);
        sort(__deck, __sets); // Order only HAND. From 0 to 6
        if(isRoyalFlush(__deck, __sets)) _isRoyal++;
        else if (isStraightFlush(__deck, __sets)) _isStraing++;
        else if (isFourOfKind(__deck, __sets)) _isFourK++;
        else if(isFullHouse(__deck, __sets)) _isFullH++;
        else if(isFlush(__deck, __sets)) _isFlush++;
        else if(isStraight(__deck, __sets)) _isStraight++;
        else if(isThreeOfKind(__deck, __sets)) _isThreeOfKind++;
        else if(isTwoPairs(__deck, __sets)) _isTwoPairs++;
        else if(isPair(__deck, __sets)) _isPair++;
        else _isAceHighOrLess++;
    }

    int _total = _isRoyal + _isStraing + _isFourK + _isFullH + _isFlush + _isStraight + _isThreeOfKind + _isTwoPairs + _isPair + _isAceHighOrLess;
    float _totalPro = _isRoyal*1.0/__cycles + _isStraing*1.0/__cycles + _isFourK*1.0/__cycles + _isFullH*1.0/__cycles +
                    _isFlush*1.0/__cycles + _isStraight*1.0/__cycles + _isThreeOfKind*1.0/__cycles + _isTwoPairs*1.0/__cycles +
                    _isPair*1.0/__cycles + _isAceHighOrLess*1.0/__cycles;

    printf("Cards: %d\n", CARDS);
    printf("Hand: %d cards\n", HAND);
    printf("Randomly Generated Hands: %d\n", MAX);
    printf(" --------------------------------------------------------\n");
    printf(" | Hand\t\t\t| Combinations\t| Probabilities |\n");
    printf(" --------------------------------------------------------\n");
    printf(" | %s\t\t| %d\t\t| %f\t|\n", "Royal Flush", _isRoyal, _isRoyal*1.0/__cycles);
    printf(" | %s\t| %d\t\t| %f\t|\n", "Straight Flush", _isStraing, _isStraing*1.0/__cycles);
    printf(" | %s\t\t| %d\t\t| %f\t|\n", "Four Of Kind", _isFourK, _isFourK*1.0/__cycles);
    printf(" | %s\t\t| %d\t\t| %f\t|\n", "Full House", _isFullH, _isFullH*1.0/__cycles);
    printf(" | %s\t\t| %d\t\t| %f\t|\n", "Flush", _isFlush, _isFlush*1.0/__cycles);
    printf(" | %s\t\t| %d\t\t| %f\t|\n", "Straight", _isStraight, _isStraight*1.0/__cycles);
    printf(" | %s\t| %d\t\t| %f\t|\n", "Three of a kind", _isThreeOfKind, _isThreeOfKind*1.0/__cycles);
    printf(" | %s\t\t| %d\t| %f\t|\n", "Two pair", _isTwoPairs, _isTwoPairs*1.0/__cycles);
    printf(" | %s\t\t\t| %d\t| %f\t|\n", "Pair", _isPair, _isPair*1.0/__cycles);
    printf(" | %s\t| %d\t| %f\t|\n", "Ace high or less", _isAceHighOrLess, _isAceHighOrLess*1.0/__cycles);
    printf(" --------------------------------------------------------\n");
    printf(" | %s\t\t| %d\t| %f\t|\n", "TOTAL", _total, _totalPro);
    printf(" --------------------------------------------------------\n");
}

int isPair(Card __deck[], int __length) {
    int _auxL[HAND] = {0};
    int _indexAux = 0;
    int _cont = 0;
    for(int i=0; i<__length-1; i++) {
        if(__deck[i]._pips == __deck[i+1]._pips) _cont++;
        else{
            _auxL[_indexAux] = _cont+1;
            _indexAux++;
            _cont = 0;
        }
    }
    _auxL[_indexAux] = _cont+1;

    int _two = 0;
    int _one = 0;
    for(int i=0; i<__length-1; i++) {
        if(_auxL[i] != 0 && _auxL[i]==1) _one++;
        if(_auxL[i] != 0 && _auxL[i]>1) _two++;
    }

    if (_two == 0 || (_two > 1 && _one == 0)) return 0;
    else if (_two == 1 && _one == 1) return 0;

    return 1;
}

int isTwoPairs(Card __deck[], int __length) {
    int _auxL[HAND] = {0};
    int _indexAux = 0;
    int _cont = 0;
    for(int i=0; i<__length-1; i++) {
        if(__deck[i]._pips == __deck[i+1]._pips) _cont++;
        else{
            _auxL[_indexAux] = _cont+1;
            _indexAux++;
            _cont = 0;
        }
    }
    _auxL[_indexAux] = _cont+1;

    int _two = 0;
    int _one = 0;
    for(int i=0; i<__length-1; i++) {
        if(_auxL[i] != 0 && _auxL[i]==1) _one++;
        if(_auxL[i] != 0 && _auxL[i]>1) _two++;
    }

    if(_two < 2 || (_two == 2 && _one == 0)) return 0;

    return 1;
}

int isThreeOfKind(Card __deck[], int __length) {
    int _auxL[HAND] = {0};
    int _indexAux = 0;
    int _cont = 0;
    for(int i=0; i<__length-1; i++) {
        if(__deck[i]._pips == __deck[i+1]._pips) _cont++;
        else{
            _auxL[_indexAux] = _cont+1;
            _indexAux++;
            _cont = 0;
        }
    }
    _auxL[_indexAux] = _cont+1;

    int _three = 0;
    int _one = 0;
    for(int i=0; i<__length-1; i++) {
        if(_auxL[i] != 0 && _auxL[i]==1) _one++;
        if(_auxL[i] != 0 && _auxL[i]>2) _three++;
    }

    if(_three == 0 || (_three == 2 && _one == 0)) return 0;

    return 1;
}

int isStraight(Card __deck[], int __length) {
    // Exist at least 5 cards consecutivas
    int _cont = 0;
    for(int i=0; i<__length-1; i++) {
        if(nextPip(__deck[i]._pips-1) == __deck[i+1]._pips-1 || __deck[i]._pips == __deck[i+1]._pips) {
            if (__deck[i]._pips != __deck[i+1]._pips) _cont++;
        } else _cont = 0;
        if(_cont==4) break;
    }

    if(_cont<4) return 0;
    return 1;
}

int isFlush(Card __deck[], int __length) {
    int _c, _d, _h, _s, _flagSuit = -1, _lengthAux = 0;
    _c = _d = _h = _s = 0;
    for(int i=0; i<__length; i++) countSuitOnHand(&_c, &_d, &_h, &_s, __deck[i]._suit);

    if (_c < 5 && _d < 5 && _h < 5 && _s < 5) return 0;

    if (_c > 4) {_flagSuit = Clubs;_lengthAux=_c;}
    else if (_d > 4) {_flagSuit = Diamonds;_lengthAux=_d;}
    else if (_h > 4) {_flagSuit = Hearts;_lengthAux=_h;}
    else if (_s > 4) {_flagSuit = Spades;_lengthAux=_s;}

    int _contPips = 0;
    for(int i=0; i<__length; i++)
        if (__deck[i]._suit == _flagSuit) _contPips++;
    if(_contPips<5) return 0;

    return 1;
}

int isFullHouse(Card __deck[], int __length) {
    int _auxL[HAND] = {0};
    int _indexAux = 0;
    int _cont = 0;
    for(int i=0; i<__length-1; i++) {
        if(__deck[i]._pips == __deck[i+1]._pips) _cont++;
        else{
            _auxL[_indexAux] = _cont+1;
            _indexAux++;
            _cont = 0;
        }
    }
    _auxL[_indexAux] = _cont+1;

    int _three = 0;
    int _two = 0;
    for(int i=0; i<__length-1; i++) {
        if(_auxL[i] != 0 && _auxL[i]==2) _two++;
        if(_auxL[i] != 0 && _auxL[i]>2) _three++;
    }
    if(_three == 0) return 0;
    else if (_three == 1 && _two == 0) return 0;

    return 1;
}

int isFourOfKind(Card __deck[], int __length) {
    int _c, _d, _h, _s, _flagSuit = -1, _lengthAux = 0;
    _c = _d = _h = _s = 0;
    for(int i=0; i<__length; i++) countSuitOnHand(&_c, &_d, &_h, &_s, __deck[i]._suit);

    if (_c < 0 || _d < 0 || _h < 0 || _s < 0) return 0;

    int _cont = 0;
    for(int i=0; i<__length-1; i++) {
        if(__deck[i]._pips == __deck[i+1]._pips) _cont++;
        else _cont = 0;
        if(_cont==3) break;
    }
    if(_cont<3) return 0;

    return 1;
}

int isStraightFlush(Card __deck[], int __length) {
    int _c, _d, _h, _s, _flagSuit = -1, _lengthAux = 0;
    _c = _d = _h = _s = 0;
    for(int i=0; i<__length; i++) countSuitOnHand(&_c, &_d, &_h, &_s, __deck[i]._suit);

    if (_c < 5 && _d < 5 && _h < 5 && _s < 5) return 0;

    if (_c > 4) {_flagSuit = Clubs;_lengthAux=_c;}
    else if (_d > 4) {_flagSuit = Diamonds;_lengthAux=_d;}
    else if (_h > 4) {_flagSuit = Hearts;_lengthAux=_h;}
    else if (_s > 4) {_flagSuit = Spades;_lengthAux=_s;}

    Card _auxDeck[__length];
    Card _tmp = {Clubs, 14};
    for(int i=0; i<__length; i++)
        if(__deck[i]._suit == _flagSuit) _auxDeck[i] = __deck[i];
        else _auxDeck[i] = _tmp;

    // Sorter Hand Auxiliar
    sort(_auxDeck, __length);

    // Exist at least 5 cards consecutivas
    int _cont = 0;
    for(int i=0; i<_lengthAux-1; i++) {
        if(nextPip(_auxDeck[i]._pips-1) == _auxDeck[i+1]._pips-1) _cont++;
        else _cont = 0;
        if(_cont==4) break;
    }

    if(_cont<4) return 0;

    return 1;
}

int isRoyalFlush(Card __deck[], int __length) {
    int _c, _d, _h, _s, _flagSuit = -1;
    _c = _d = _h = _s = 0;
    int _ace, _ten, _jack, _queen, _king, _contPips;
    _ace = _ten = _jack = _queen = _king = _contPips = 0;
    for(int i=0; i<__length; i++) {
        countSuitOnHand(&_c, &_d, &_h, &_s, __deck[i]._suit);
        if (__deck[i]._pips == Ace+1 || __deck[i]._pips == Ten+1 || __deck[i]._pips == Jack+1 || __deck[i]._pips == Queen+1 || __deck[i]._pips == King+1 ) _contPips++;
    }
    // assert(_c==5);
    // assert(_contPips>4);
    if (!((_c > 4 || _d > 4 || _h > 4 || _s > 4) && _contPips > 4)) return 0;
    _contPips = 0;
    if (_c > 4) _flagSuit = Clubs;
    else if (_d > 4) _flagSuit = Diamonds;
    else if (_h > 4) _flagSuit = Hearts;
    else if (_s > 4) _flagSuit = Spades;
    for(int i=0; i<__length; i++)
        if ((__deck[i]._pips == Ace+1 || __deck[i]._pips == Ten+1 || __deck[i]._pips == Jack+1 || __deck[i]._pips == Queen+1 || __deck[i]._pips == King+1) &&
            __deck[i]._suit == _flagSuit) _contPips++;
    if(_contPips == 5) return 1;
    return 0;
}

void shuffle(Card __deck[], int __length) {
    Card _aux;
    int _randValue;
    for (int i=0; i<__length; i++) {
        _randValue = rand() % CARDS; // 0 to 51
        _aux = __deck[i];
        __deck[i] = __deck[_randValue];
        __deck[_randValue] = _aux;
    }
}

char nameSuit(Suit __suit) {
    switch(__suit) {
        case Clubs:
            return 'C';
        case Diamonds:
            return 'D';
        case Hearts:
            return 'H';
        case Spades:
            return 'S';
        default:
            return 'N';
    }
}

void print(Card __deck[], int __length) {
    printCards(__deck, 0, 14);
    printCards(__deck, 15, 29);
    printCards(__deck, 30, 44);
    printCards(__deck, 45, 51);
}

void printCards(Card __deck[], int __indexStart, int __indexEnd) {
    printf("\n     ");
    for (int j = __indexStart; j < __indexEnd+1; j++) printf("%d\t     ", j+1);
    printf("\n  ");
    for (int j = __indexStart; j < __indexEnd+1; j++) printf(" -----  ");
    printf("\n  | ");
    for (int j = __indexStart; j < __indexEnd+1; j++)
        if((j+1)%(__indexEnd+1)==0)printf("%c%c\t|", ' ', ' ');else printf("%c%c\t| | ", ' ', ' ');
    printf("\n  | ");
    for (int j = __indexStart; j < __indexEnd+1; j++)
        if((j+1)%(__indexEnd+1)==0)printf("%d%c\t|", __deck[j]._pips, nameSuit(__deck[j]._suit));else printf("%d%c\t| | ", __deck[j]._pips, nameSuit(__deck[j]._suit));
    printf("\n  | ");
    for (int j = __indexStart; j < __indexEnd+1; j++)
        if((j+1)%(__indexEnd+1)==0)printf("%c%c\t|", ' ', ' ');else printf("%c%c\t| | ", ' ', ' ');
    printf("\n  ");
    for (int j = __indexStart; j < __indexEnd+1; j++) printf(" -----  ");
    printf("\n");
}

void initDeck(Card __deck[], int __length) {
    int _flagSuit = 0;
    int _flagPips = 1;
    for (int i = 0; i < __length; i++) {
        __deck[i]._pips = _flagPips++;
        __deck[i]._suit = _flagSuit;
        if((i+1) % PIPS == 0) {
            _flagSuit++;
            _flagPips = 1;
        }
    }
}

Pips nextPip(Pips __pip) {
    return (__pip + 1) % PIPS;
}

void countSuitOnHand(int *__clubs, int *__diamonds, int *__hearts, int *__spades, Suit __suit) {
    if (__suit == Clubs) (*__clubs)++;
    else if (__suit == Diamonds) (*__diamonds)++;
    else if (__suit == Hearts) (*__hearts)++;
    else if (__suit == Spades) (*__spades)++;
}

void sort(Card __deck[], int __length) {
    int _flag = 0;
    Card _aux;
    for(int i=0; i<__length-1; i++) {
        for(int j=0; j<__length-i-1; j++) {
            if(__deck[j]._pips > __deck[j+1]._pips) {
                _aux = __deck[j];
                __deck[j] = __deck[j+1];
                __deck[j+1] = _aux;
                _flag = 1;
            }
        }
        if(!_flag) break;
    }
}

void test() {
    // Card _test[HAND] = {{Clubs, 10},{Clubs, 11},{Clubs, 12},{Clubs, 13},{Clubs, 1},{Diamonds, 9},{Spades, 5}};
    // if(isRoyalFlush(_test, HAND)) printCards(_test, 0, HAND-1);
    // Card _test1[HAND] = {{Clubs, 1},{Clubs, 6},{Clubs, 6},{Clubs, 8},{Clubs, 9},{Diamonds, 12},{Spades, 13}};
    // isStraightFlush(_test1, HAND);
    // Card _test2[HAND] = {{Clubs, 1},{Clubs, 3},{Clubs, 3},{Clubs, 5},{Clubs, 7},{Diamonds, 8},{Spades, 11}};
    // isStraightFlush(_test2, HAND);
    // Card _test3[HAND] = {{Clubs, 1},{Clubs, 2},{Clubs, 3},{Clubs, 8},{Clubs, 9},{Diamonds, 10},{Spades, 11}};
    // isStraightFlush(_test3, HAND);
    // Card _test4[HAND] = {{Clubs, 2},{Clubs, 3},{Clubs, 4},{Clubs, 5},{Clubs, 6},{Diamonds, 10},{Spades, 11}};
    // isStraightFlush(_test4, HAND);
    // Card _test5[HAND] = {{Clubs, 2},{Clubs, 3},{Clubs, 4},{Spades, 4},{Clubs, 5},{Diamonds, 6},{Spades, 7}};
    // isStraightFlush(_test5, HAND);
    // Card _test6[HAND] = {{Clubs, 2},{Clubs, 3},{Clubs, 4},{Spades, 4},{Clubs, 5},{Diamonds, 5},{Spades, 6}};
    // isStraightFlush(_test6, HAND);
    // Card _test7[HAND] = {{Clubs, 1},{Clubs, 3},{Clubs, 4},{Clubs, 10},{Clubs, 11},{Diamonds, 12},{Spades, 13}};
    // isStraightFlush(_test7, HAND);
    // Card _test8[HAND] = {{Clubs, 1},{Clubs, 2},{Clubs, 3},{Clubs, 9},{Clubs, 11},{Diamonds, 12},{Spades, 13}};
    // isStraightFlush(_test8, HAND);
    // Card _test9[HAND] = {{Clubs, 1},{Clubs, 2},{Clubs, 3},{Clubs, 4},{Clubs, 11},{Diamonds, 12},{Spades, 13}};
    // isStraightFlush(_test9, HAND);
    // Card _test10[HAND] = {{Clubs, 2},{Clubs, 3},{Clubs, 4},{Spades, 4},{Clubs, 5},{Diamonds, 5},{Clubs, 6}};
    // isStraightFlush(_test10, HAND);
    // Card _test11[HAND] = {{Hearts, 6},{Spades, 9},{Hearts, 9},{Hearts, 10},{Hearts, 11},{Spades, 12},{Hearts, 13}};
    // isStraightFlush(_test11, HAND);
    // Card _test12[HAND] = {{Hearts, 6},{Spades, 9},{Hearts, 9},{Hearts, 10},{Hearts, 11},{Hearts, 12},{Hearts, 13}};
    // isStraightFlush(_test12, HAND);
    // Card _test13[HAND] = {{Hearts, 9},{Spades, 9},{Clubs, 9},{Hearts, 10},{Hearts, 11},{Hearts, 12},{Hearts, 13}};
    // isStraightFlush(_test13, HAND);
    // Card _test14[HAND] = {{Hearts, 6},{Hearts, 9},{Spades, 9},{Hearts, 10},{Hearts, 11},{Hearts, 12},{Hearts, 13}};
    // isStraightFlush(_test14, HAND);
    // Card _test15[HAND] = {{Hearts, 10},{Spades, 10},{Clubs, 10},{Diamonds, 10},{Hearts, 11},{Hearts, 12},{Hearts, 13}};
    // isStraightFlush(_test15, HAND);
    // Card _test16[HAND] = {{Clubs, 3},{Hearts, 4},{Clubs, 5},{Clubs, 6},{Clubs, 7},{Hearts, 7},{Clubs, 12}};
    // isStraightFlush(_test16, HAND);
    // Card _test17[HAND] = {{Clubs, 1},{Clubs, 3},{Clubs, 4},{Clubs, 10},{Clubs, 11},{Clubs, 12},{Clubs, 13}};
    // isStraightFlush(_test17, HAND);
    Card _test18[HAND] = {{Clubs, 2},{Diamonds, 3},{Spades, 5},{Clubs, 6},{Hearts, 7},{Spades, 8},{Clubs, 12}};
    isStraight(_test18, HAND);
}
