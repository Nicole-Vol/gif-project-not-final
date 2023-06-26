#ifndef LINKEDLISTH
#define LINKEDLISTH

#define FALSE 0
#define TRUE !FALSE
#define PATH_SIZE 100
#define FRAME_NAME_SIZE 11

// Frame struct
typedef struct Frame
{
	char		name[FRAME_NAME_SIZE];
	unsigned int	duration;
	char		path[PATH_SIZE];
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;


/*
function for scanning a string input from user,
according to a MAX amount of characters.
input:
output: None
*/
void myFgets(char str[], int n);


// ***FUNCTIONS ACCORDING TO ACTIONS' OPTIONS*** //


/*
function for adding a new frame to the movie(linked list)
input: the list of frames(the first node)
output: none
*/
void add_new_frames(FrameNode** head);

/*
function for deleting a frame from the GIF clio,
by specifise which frame to delete,
according to the name of the frame.
input:
output: None
*/
void delete_frame_by_name(FrameNode** head, char* name);




/*
function for changing the duration of the while GIF clip,
by the help of the function "change_frame_function()",
by changing the length of each frame to the same using a mathmatical calc.

input: linked list(first node)
output:
*/
void change_whole_clips_duration(FrameNode* head);


/*
function for printing the content of each node in the list,
that reperesents the info. about the specific frame-node.

input: linked list(first node)
output: none
*/
void print_linked_list(FrameNode* head);


/*
function for checking if a frame with the entered name,
has already existed.
input:
output: 1 - if exisitng, 0 - if not
*/
int isFrameNameExists(FrameNode* head, char* name);

/*
function for checking if the file is existing,
for opening the frame's image file.
input: path
output: 1 if file exists, 0 - if does not exist
*/
int checkImageFileExistence(char* path);


/*
function for scanning from user,
the name of the frame that would be liked to be deleted,
and the deletes it.
input:
output: None
*/
void scan_from_user_and_remove_frame(FrameNode** head);

/*
function for changing the duration of the while GIF clip,
by the help of the function "change_frame_function()",
by changing the length of each frame to the same using a mathmatical calc.

input: linked list(first node)
output:
*/
void change_whole_clips_duration(FrameNode* head);

/*
function for scanning the index for the new position of the frame,
from the user.
input: None
output: The new wanted index - int
*/
int scanning_new_index_from_user();

/*
function for scaning the frame's name,
that is ment to move its index
input: none
output: the frame's name
*/
char scanning_frame_name_to_move();

/*
function for changing the frames index, according to the users input and wish.
input:
output: none
*/
void changing_index_of_frames(FrameNode** head);




#endif
