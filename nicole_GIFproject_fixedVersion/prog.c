/*********************************
* Class: MAGSHIMIM C2			 *
* GIF project                    *
* Using user header files		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "menualUserInteractions.h"
#include "view.h"

#define FALSE 0

int main(void)
{
    // declairing variables // 
    FrameNode* head = NULL;
    int users_action_choice = 0;
    int i = 1;

    printf("checking print BEFORE THE MENU PRINT func.\n");

    print_clip_actions_menu();
    printf("checking print after func.\n");


    while (i)
    {
        // scanning user's choice
        printf("your choice: ");
        scanf("%d", &users_action_choice);
        getchar();
        printf("THE CHOICE IS %d\n", users_action_choice);

        if ((users_action_choice >= 0) && (users_action_choice <= 8))
        {
            printf("AFTER IF - SWITCH CASE\n");
            switch (users_action_choice)
            {
            case 0:
            {
                // Exiting the program
                printf("You've decided to exit.\nBye!");
                i = 0;  // Changed the value to exit the while loop
                break;
            }

            case 1:
            {
                // Calling function to add a frame
                printf("\nyou've chosen to add a frame.\n");
                add_new_frames(&head);  // Pass the address of head
                break;
            }

            case 2:
            {
                // Calling function to remove a frame
                printf("\nyou've chosen to erase a frame.\n");
                scan_from_user_and_remove_frame(head);
                break;
            }

            case 3:
            {
                // Calling function to change frame index
                printf("\nyou've chosen to change the index - position of a frame.\n");
                changing_index_of_frames(head);
                break;
            }

            case 4:
            {
                // Calling function to change the frame's duration
                printf("\nyou've chosen to change a frame's duration.\n");
                // Implement the necessary code here
                break;
            }

            case 5:
            {
                // Calling function to change duration of all frames
                printf("\nyou've chosen to change the duration of all frames.\n");
                change_whole_clips_duration(head);
                break;
            }

            case 6:
            {
                // Calling function to list all the frames
                printf("printing frames list...\n");
                print_linked_list(head);
                printf("done!\n");
                break;
            }

            case 7:
            {
                // Calling function to play the movie that was made
                play(head);
                break;
            }

            case 8:
            {
                // Calling function to save the whole project
                printf("\nyou've chosen to save the project.\n");
                // Implement the necessary code here
                break;
            }
            }
        }
        else
        {
            printf("The option you entered is not valid. Please try again.\n");
        }
    }

    getchar();
    return 0;
}
