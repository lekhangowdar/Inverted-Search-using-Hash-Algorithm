/***************************************************************************************************************************************************
*Author         :Lekhan Gowda R
*Date           :Tue 5 nov 2024 8:06:15 IST
*File           :read_datafile
*Title          :To process the files one by one
*Description    :Open the file “FileList” and read the names of the files. This is an iterative process which reads one file name from the 
		:FileList and open that file in read mode.
****************************************************************************************************************************************************/
#include "inverted_search.h"

void read_datafile(Flist **file, main_ll* head[], unsigned int create_f)
{
	// Declaring Function prototype for copying file content into the list
	int copy_savefile_to_list(main_ll *head[], char *savef); 

	// Check if the database is not yet created (create_f == 0)
	if(create_f == 0)
	{
		char file_name[50];  // Array to store the file name
		// Ask the user for the file name to update the database
		printf("Pass the file in which database is to be updated: ");
		scanf("%s", file_name);

		// Check if the file has a ".txt" extension
		if(strstr(file_name,".txt") == NULL)
		{
			// If the file name is invalid, notify the user
			printf("Pass the correct file name (e.g., file_name.txt)!!\n");
			return;
		}
		
		// Copy the contents of the file into the database if the file is valid
		if(copy_savefile_to_list(head, file_name) == SUCCESS)	
			printf("\n----------PREVIOUS FILE/s HAVE BEEN UPDATED--------\n");
		else
			// If updating fails, notify the user
			printf("\n-----------------UPDATE DATABASE FAILURE---------------");
	}
	else
	{
		// If the database has already been created, display an error message
		printf("\n-----------------UPDATE DATABASE FAILURE---------------");
		printf("\n----------PREVIOUS FILE/s HAVE ALREADY BEEN UPDATED----------\n");
	}
}
