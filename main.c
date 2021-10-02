#include <stdio.h>
#define clear_screen() printf("\e[1;1H\e[2J")

void get_user_choice(char* c);
int choice_valid(const char* c);
void clear_keyboard_buffer(void);
void withdraw(int *ptr_energy);
void deposit(int *ptr_energy);

int main() {
    int energy = 100;
    char choice = '0'; //initialize choice to an irrelevant value.

    while (choice != 'q') {
        printf("Current Energy: %d\n", energy);
        get_user_choice(&choice);
        if (choice == 'w')
            withdraw(&energy);
        else if (choice == 'd')
            deposit(&energy);
        clear_screen();
    }
    return 0;
}

void get_user_choice(char* c) {
    char temp;

    do {
        printf("What would you like to do:\n"
               "[w]ithdraw\n"
               "[d]eposit\n"
               "[q]uit\n");

        scanf("%c", &temp);
        clear_keyboard_buffer();
    } while(!choice_valid(&temp));

    *c = temp;
}

int choice_valid(const char *c) {
    return (*c == 'q' || *c == 'w' || *c == 'd') ;
}

void clear_keyboard_buffer(void) {
    char c;
    do {
        scanf("%c", &c);
    } while (c != '\n');
}

void withdraw(int *ptr_energy) {
    int noc, spent_energy;
    printf("How much energy have you spent? ");
    noc = scanf("%d", &spent_energy);
    clear_keyboard_buffer();

    while (noc != 1 || spent_energy < 0) {
        printf("Please enter a positive integer: ");
        noc = scanf("%d", &spent_energy);
    }
    *ptr_energy -= spent_energy;
}

void deposit(int *ptr_energy) {
    int noc, gained_energy;
    printf("How much energy have you regained? ");
    noc = scanf("%d", &gained_energy);
    clear_keyboard_buffer();

    while (noc != 1 || gained_energy < 0) {
        printf("Please enter a positive integer: ");
        noc = scanf("%d", &gained_energy);
    }
    *ptr_energy += gained_energy;
}

