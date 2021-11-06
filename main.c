#include <stdio.h>
#include <stdbool.h>
#define clear_screen() printf("\e[1;1H\e[2J")

//Precondition: None
//Postcondition: User will have been prompted to withdraw energy,
// deposit energy, or quit
char get_user_choice(void);

//Precondition: none
//Postcondition: Return true if c is 'w', 'd', or 'q'
bool choice_valid(char c);

//Precondition: none
//Postcondition: Keyboard Buffer has been cleared
void clear_keyboard_buffer(void);

//Precondition: none
//Postcondition: User has been asked how much energy they have
// spent. energy - the amount the user specified is returned
int withdraw(int energy);

//Precondition: None
//Postcondition: User has been asked how much energy they have
// gained. energy + the amount the user specified is returned
int deposit(int energy);

int main(void)
{
	int energy = 100;
	char choice = '0'; //initialize choice to an irrelevant value.

	while (choice!='q') {
		printf("Current Energy: %d\n", energy);
		choice = get_user_choice();
		switch (choice) {
		case 'w': energy = withdraw(energy);
			break;
		case 'd': energy = deposit(energy);
			break;
		default: break;
		}
		clear_screen();
	}
	return 0;
}

char get_user_choice(void)
{
	char temp;

	do {
		printf("[w]ithdraw\n"
			   "[d]eposit\n"
			   "[q]uit\n"
			   "What would you like to do: ");

		scanf("%c", &temp);
		clear_keyboard_buffer();
	} while (!choice_valid(temp));

	return temp;
}

bool choice_valid(char c)
{
	return (c=='q' || c=='w' || c=='d');
}

void clear_keyboard_buffer(void)
{
    char c;
    do {
        scanf("%c", &c);
    } while (c != '\n');
}

int withdraw(int energy)
{
	int noc, spent_energy;
	printf("How much energy have you spent? ");
	noc = scanf("%d", &spent_energy);
	clear_keyboard_buffer();

	while (noc!=1 || spent_energy<0) {
		printf("Please enter a positive integer: ");
		noc = scanf("%d", &spent_energy);
	    clear_keyboard_buffer();
	}
	return energy-spent_energy;
}

int deposit(int energy)
{
	int noc, gained_energy;
	printf("How much energy have you regained? ");
	noc = scanf("%d", &gained_energy);
	clear_keyboard_buffer();

	while (noc!=1 || gained_energy<0) {
		printf("Please enter a positive integer: ");
		noc = scanf("%d", &gained_energy);
	    clear_keyboard_buffer();
	}
	return energy+gained_energy;
}

