/***************************************************************************************************************************************************
*Author         :Lekhan Gowda R
*Date           :Tue 5 nov 2024 8:06:15 IST
*File           :write_datbasefile.c
*Title          :Saves the details into the file
*Description    :All the files are opened and read. Words are listed. Now this list is to be stored. 
		:For this a new file “DatabaseFile” is created and opened in write mode. 
		:Now the words along with filelist (each node contents) are written to the Database file. 
		:In the file also the word should be written in sorted order. 
		:After that the file is closed properly.
****************************************************************************************************************************************************/
#include "inverted_Search.h"

void write_databasefile(main_ll *head[])
{
	printf("\n------------------------SAVING DATABASE---------------------------\n");
	char file_name[50];
	
	// Prompt user for the file name to save the database
	printf("Pass the file in which database is to be saved : ");
	scanf("%s", file_name);

	// Check if the provided file name has a ".txt" extension
	if (strstr(file_name, ".txt") == NULL)
	{
		// Print error if the file name is incorrect
		printf("Pass the correct file name (ex: file_name.txt)\n");
		return;
	}

	// Open the file in write mode
	FILE *fptr = fopen(file_name, "w");
	if (fptr == NULL)
	{
		// Error if the file cannot be opened
		printf("Error opening file '%s'\n", file_name);
		return;
	}

	// Loop through all 27 possible indexes (one for each letter of the alphabet and an additional one for non-alphabetic words)
	int i;
	for (i = 0; i < 27; i++)
	{
		// Skip empty lists
		if (head[i] == NULL)
		{
			continue;
		}
		
		// Get the head of the list for the current index
		main_ll *head_m = head[i];
		
		// Write the index marker (e.g., #0#, #1#, etc.)
		fprintf(fptr, "#%d#\n", i);

		// Traverse through the list of words at the current index
		while (head_m != NULL)
		{
			// Write the word and its file count to the file
			fprintf(fptr, "%s:%d", head_m->word, head_m->file_count);

			// Traverse through the list of files associated with the current word
			sub_ll *Thead = head_m->Tlink;
			while (Thead)
			{
				// Write the file name and the word count for that file to the file
				fprintf(fptr, ":%s:%d", Thead->file_name, Thead->word_count);
				Thead = Thead->table_link;
			}

			// Move to the next word in the list
			fprintf(fptr, "\n");
			head_m = head_m->link;
		}
	}

	// Close the file after saving
	fclose(fptr);

	// Inform the user that the database was saved successfully
	printf("Database is saved successfully in '%s'\n", file_name);
}

