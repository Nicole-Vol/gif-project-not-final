/********************************************
* Class: MAGSHIMIM C2						*
* GIF project      							*
* Implementation of projectRelatedActions.  *
*********************************************/

#include <stdio.h>

#include "projectRelatedActions.h"


/*
function for checking if a file is existing,
according to the file's path.
input: file path
output: 0 - if file exists
		1 - else(error in opening or file diesnt exists)
*/
int check_file_existance(char* path) 
{
	printf("CHECKING IF FILE EXISTS\n");
	FILE* file = NULL;
	char ch = ' ';

	file = fopen(path, "r");
	if (file == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	printf("file exists\n");
}

/*
function for reading the existing file
input: file's path
output:
*/
FILE* read_and_get_exising_file(char* path)
{
	printf("\n");
	return NULL;
}

/*
function for saving the maded GIF clip
input: file path for saving
output:
*/
FILE* save_and_write_to_file(char* path)
{
	printf("\n");
	return NULL;
}


