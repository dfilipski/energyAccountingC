#include <stdio.h>

void getUserChoice(char* c);
int choiceValid(char* c);
void clearKeyboardBuffer(void);

int main() {
    int energyMax = 100;
    int energy = energyMax;
    char c = '0'; //initialize c to an irrelevant value.

    while (c != 'q') {
        printf("Current Energy: %d\n", energy);
        getUserChoice(&c);
    }
    return 0;
}

void getUserChoice(char* c) {
    char tempChar;

    do {
        printf("What would you like to do:\n"
               "[w]ithdraw\n"
               "[d]eposit\n"
               "[q]uit\n");

        scanf("%c", &tempChar);
        clearKeyboardBuffer();
    } while(!choiceValid(&tempChar));

    *c = tempChar;
}

int choiceValid(char *c) {
    return (*c == 'q' || *c == 'w' || *c == 'd') ;
}

void clearKeyboardBuffer(void) {
    char c;
    do {
        scanf("%c", &c);
    } while (c != '\n');
}

