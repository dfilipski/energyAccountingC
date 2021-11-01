#include <stdio.h>
#include <stdbool.h>
#define clear_screen() printf("\e[1;1H\e[2J")

char get_user_choice(void);
bool choice_valid(char c);
void clear_keyboard_buffer(void);
int withdraw(int energy);
int deposit(int energy);

int main() {
    int energy = 100;
    char choice = '0'; //initialize choice to an irrelevant value.

    while (choice != 'q') {
        printf("Current Energy: %d\n", energy);
        choice = get_user_choice();
        if (choice == 'w')
            energy = withdraw(energy);
        else if (choice == 'd')
            energy = deposit(energy);
        clear_screen();
    }
    return 0;
}

char get_user_choice(void) {
    char temp;

    do {
        printf("What would you like to do:\n"
               "[w]ithdraw\n"
               "[d]eposit\n"
               "[q]uit\n");

        scanf("%c", &temp);
        clear_keyboard_buffer();
    } while(!choice_valid(temp));

    return temp;
}

bool choice_valid(char c) {
    return (c == 'q' || c == 'w' || c == 'd') ;
}

void clear_keyboard_buffer(void) {
    char c;
    do {
        scanf("%c", &c);
    } while (c != '\n');
}

int withdraw(int energy) {
    int noc, spent_energy;
    printf("How much energy have you spent? ");
    noc = scanf("%d", &spent_energy);
    clear_keyboard_buffer();

    while (noc != 1 || spent_energy < 0) {
        printf("Please enter a positive integer: ");
        noc = scanf("%d", &spent_energy);
    }
    return energy - spent_energy;
}

int deposit(int energy) {
    int noc, gained_energy;
    printf("How much energy have you regained? ");
    noc = scanf("%d", &gained_energy);
    clear_keyboard_buffer();

    while (noc != 1 || gained_energy < 0) {
        printf("Please enter a positive integer: ");
        noc = scanf("%d", &gained_energy);
    }
    return energy + gained_energy;
}

