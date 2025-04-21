/***************************************************************************************************************************************************
*Author         :Lekhan Gowda R
*Date           :Tue 5 nov 2024 8:06:15 IST
*File           :create_database.c
*Title          :To create the database
*Description    :The list of the files can be provided by storing all the file names in another file, FileList the names of the files which 
		:are to be documented are provided by this file. When a file is added or removed, FileList is changed accordingly.
		:So read the file names and start indexing.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int create_database(Flist *fname, main_ll **head)
{
	printf("------------------------------CREATING A DATABASE------------------------------\n");
    char word[100];          // Buffer to hold each word read from files
	FILE *fptr;

	// Traverse through the file list to process each file
    while(fname)
    {
		// Open the current file in read mode
		fptr = fopen(fname->file_name, "r");
		if(fptr == NULL)
		{
			// Print error and continue to next file if opening fails
			printf("Failed to open file %s\n", fname->file_name);
			fname = fname->link;  // Move to the next file in the list
            continue;
		}

		// Read each word from the file until EOF is reached
		while(fscanf(fptr, "%s", word) != EOF)
		{
			// Store each word in the inverted index database
			store_word(word, fname->file_name, head);
		}
		printf("Database is created for %s\n", fname->file_name); // Confirmation message
		
		// Close the file after processing
		fclose(fptr);

		// Move to the next file in the list
		fname = fname->link;
    }

	printf("------------------------------DATABASE IS CREATED------------------------------\n");
}
