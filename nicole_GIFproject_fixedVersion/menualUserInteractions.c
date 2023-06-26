/*********************************
* Class: MAGSHIMIM C2			 *
* GIF project      				 *
* Implementation of menualUserInteractions.  *
**********************************/

#include <stdio.h>

#include "menualUserInteractions.h"


/*
function for printing menu for actions
input: none
output: none
*/
void print_clip_actions_menu()
{
	printf("What would you like to do?\n");
	printf(" [-] Exit\n");
	printf(" [1] Add new Frame\n");
	printf(" [2] Remove a Frame\n");
	printf(" [3] Change frame index\n");
	printf(" [4] Change frame duration\n");
	printf(" [5] Change duration of all frames\n");
	printf(" [6] List frames\n");
	printf(" [7] Play movie!\n");
}


/*
function for scanning from the user,
the chosen action from the GIF menu,
by a number.
input: none
output: the chosen action(int)

int scan_action_from_user()
{
	// declairing variable 
	int chosen_action = 0;

	// scanning user's choice
	printf("your choice: ");
	scanf("%d", &chosen_action);
	getchar();

	printf("FUNCTION CHECK: THE CHOICE IS %d\n", chosen_action);

	return chosen_action;
}
*/


