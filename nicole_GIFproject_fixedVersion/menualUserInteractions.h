#ifndef MENUALUSERINTERACTIONSH
#define MENUALUSERINTERACTIONSH

/*
function for printing menu of options for opening the project
input: none
output: none
*/
void print_project_options();

/*
function for scaning user's choice that is related to the project's opening
input: none
output: the chosen action(int)
*/
int scan_project_open_option();


/*
function for scanning a path file,
for saving the GIF clip according to that.
input: none
output: file's path
*/
char* scan_file_path();


/*
function for printing menu for actions
input: none
output: none
*/
void print_clip_actions_menu();


/*
function for scanning from the user,
the chosen action from the GIF menu,
by a number.
input: none
output: the chosen action(int)
*/
int scan_action_from_user();


/*
function for scanning from user, 
a frames name,
to pass later to functions,
which are related to the chosen action.
input: none
output: returning name of the frame - string
*/
char* scan_frame_name_for_actions();


#endif
