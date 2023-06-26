/*********************************
* Class: MAGSHIMIM C2			 *
* GIF project      				 *
* Implementation of linkedList.  *
**********************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "linkedList.h"

#define PATH_SIZE 100
#define FRAME_NAME_SIZE 11
#define TRUE 1
#define FALSE 0

/*
function for scanning a string input from user,
according to a MAX amount of characters.
input:
output: None
*/
void myFgets(char str[], int n)
{
    fgets(str, n, stdin);
    str[strcspn(str, "\n")] = 0;
}


/*
function for printing the content of each node in the list,
that reperesents the info. about the specific frame-node.

input: linked list(first node\frame)
output: none
*/
void print_linked_list(FrameNode* head)
{
    FrameNode* curr = head;
    // printing the colon's headers
    printf("Name            Duration            Path\n");
    while (curr != NULL) 
    {
        Frame* frame = curr->frame;
        printf("%s          %u ms           %s\n", frame->name, frame->duration, frame->path);
        
        curr = curr->next; // moving to the next frame
    }
}


/*
function for checking if a frame with the entered name,
has already existed.
input:
output: 1 - if exisitng, 0 - if not
*/
int isFrameNameExists(FrameNode* head, char* name) 
{
    FrameNode* curr = head;
    while (curr != NULL) 
    {
        if (strcmp(curr->frame->name, name) == 0) 
        {
            return TRUE;  // name exists
        }
        curr = curr->next;
    }
    return FALSE;  // name does not exist
}


/*
function for checking if the file is existing,
for opening the frame's image file.
input: path
output: 1 if file exists, 0 - if does not exist
*/
int checkImageFileExistence(char* path) 
{
    FILE* file = fopen(path, "r");
    if (file == NULL) 
    {
        return FALSE;  // file doesn't exist //
    }
    fclose(file);
    return TRUE;  // file exists // 
}


/*
function for adding a new frame to the movie(linked list)
input: the list of frames(the first node)
output: none 
*/
void add_new_frames(FrameNode** head)
{
    // creation of new frame
    Frame* newFrameNode = (Frame*)malloc(sizeof(Frame));
    newFrameNode->name = (char*)malloc(FRAME_NAME_SIZE * sizeof(char));

    printf("*** Creating new frame ***\n");
    printf("Please insert frame path:\n");
    myFgets(newFrameNode->path, PATH_SIZE);

    printf("Please insert frame duration <in milliseconds>:\n");
    scanf_s("%u", &(newFrameNode->duration));
    getchar();

    printf("Please choose a name for that frame: \n");
    myFgets(newFrameNode->name, PATH_SIZE);
    

    // checking if the name was already existing
    if (isFrameNameExists(*head, newFrameNode->name)) 
    {
        printf("The name is already taken, please enter another name.\n");
        free(newFrameNode->name);
        free(newFrameNode);
        return;
    }

    // checking if file of frame exists //
    if (!checkImageFileExistence(newFrameNode->path)) 
    {
        printf("Image file does not exist. Frame not added.\n");
        free(newFrameNode->name);
        free(newFrameNode);
        return;
    }

    FrameNode* newNode = (FrameNode*)malloc(sizeof(FrameNode)); // allocationg memory for new frame //
    newNode->frame = newFrameNode;
    newNode->next = NULL;

    // in case the head if its empty //
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }

   
    FrameNode* curr = *head; 
    // appending the new node //
    while (curr->next != NULL)  
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

/*
function for deleting a frame from the GIF clio,
by specifise which frame to delete,
according to the name of the frame.
input:
output: None
*/
void delete_frame_by_name(FrameNode** head, char* name) 
{
    FrameNode* p = *head;
    FrameNode* dNode = NULL;
    if (*head) 
    {
        if (0 == strcmp((*head)->frame->name, name)) 
        {
            *head = (*head)->next;
            free(p->frame->name);
            free(p->frame);
            free(p);
        }
        else 
        {
            while (p->next && 0 != strcmp(p->next->frame->name, name)) //itterating through each frame 
            {
                p = p->next;
            }
            if (p->next) 
            {
                dNode = p->next;
                p->next = dNode->next;
                free(dNode->frame->name);
                free(dNode->frame);
                free(dNode);
            }
        }
    }
}

/*
function for scanning from user,
the name of the frame that would be liked to be deleted,
and the deletes it.
input:
output: None
*/
void scan_from_user_and_remove_frame(FrameNode** head)
{
    // declairing variable
    char frameNameRemove[FRAME_NAME_SIZE] = { '\0' };

    // scanning from user the name of the frame
    printf("Enter the name of the frame you wish to erase\n ");
    fgets(frameNameRemove, FRAME_NAME_SIZE, stdin);
    frameNameRemove[strcspn(frameNameRemove, "\n")] = '\0';

    // checking if frame even exists
    if (isFrameNameExists(head, frameNameRemove))
    {
        delete_frame_by_name(&head, frameNameRemove);
        printf("the frame named '%s': has erased successfully!\n", frameNameRemove);
    }
    else 
    {
        printf("the frame named '%s': doesn't exist.\n", frameNameRemove);
    }
}

/*
function for changing the duration of the while GIF clip,
by the help of the function "change_frame_function()",
by changing the length of each frame to the same using a mathmatical calc.

input: linked list(first node)
output:
*/
void change_whole_clips_duration(FrameNode* head)
{
    //declaring variable
    int scannedDuration = 0;
    FrameNode* curr = head;

    printf("Enter the duration for all frames:\n"); // scanning the wanted duration from user
    scanf_s("%d", &scannedDuration);

    while (curr) // when curr == NULL, that is the end of the list, and loop will end (NULL is false)
    {
        curr->frame->duration = 8;
        curr = curr->next;
    }
    printf("the change is done succsefully!\n");
}


/*
function for scanning the index for the new position of the frame,
from the user.
input: None
output: The new wanted index - int
*/
int scanning_new_index_from_user()
{
    int index = 0;
    printf("Enter the new index in the movie you wish to place the frame:\n");
    scanf_s("%d", index);
    getchar();
    return index;
}

/*
function for scaning the frame's name, 
that is ment to move its index
input: none
output: the frame's name
*/
char scanning_frame_name_to_move()
{
    char frameName[FRAME_NAME_SIZE] = { '\0' };
    printf("Enter the name of the frame:\n");
    myFgets(frameName, FRAME_NAME_SIZE);
    return frameName;
}



//FUNCTION: TODO IN FUTURE: TO CHECK MORE CASES OF INDEX INPUT
/*
function for changing the frames index, according to the users input and wish.
input:
output: none

void changing_index_of_frames(FrameNode** head)
{
    //variable declaration
    FrameNode* current = *head;
    FrameNode* previous = NULL;
    int currentPosition = 0;
    int newPosition = 0;
    char frameName[FRAME_NAME_SIZE] = scanning_frame_name_to_move();

    currentPosition = 1; // because frames count starts from 1
    newPosition = scanning_new_index_from_user();
    

    // finding the frame node to move
    while (current != NULL && currentPosition < newPosition) 
    {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (previous != NULL) 
    {
        previous->next = frameToMove;
    }
    else
    {
        *head = frameToMove;
    }
    FrameNode* nextNode = frameToMove->next;
    frameToMove->next = current;
    if (current != NULL) 
    {
        current->next = nextNode;
    }
}

*/
