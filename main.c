/***************************************************************************************************************************************************
*Author		:Lekhan Gowda R
*Date		:Tue 5 nov 2024 8:06:15 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"

int main(int argc, char *argv[])
{
	// Define the main function here 
	Flist *fname = NULL;
	
	// Validate input arguments and initialize file list
	if(read_validate(argv, argc, &fname) == FAILURE)
	{
		return 0; // Exit if validation fails
	}
	
	// Initialize hash table (26 letters + 1 for non-alphabetic entries)
	main_ll *head[27] = {NULL};

	// Check if the file list is empty
	if(fname == NULL)
	{
		return 0; // Exit if no files were added
	}

	unsigned int choice, create_f = 0;
	while(1)
	{
	    // Display menu options
	    printf("\n-------------------MENU----------------\n");
		printf("1. Create Database\n2. Display Database\n3. Search Word\n4. Update Database\n5. Save Database\n6. Exit");
		printf("\nEnter the choice : ");
		scanf("%d", &choice);

		// Handle menu options based on user choice
		switch(choice)
		{
			case 1: 
					// Create the inverted index database
					create_database(fname, head);
					create_f = 1;  // Mark database as created
					break;
			case 2: 
					// Display the entire inverted index database
					display_database(head);
					break;
			case 3:
				{
					// Search for a specific word in the database
					char word[50];
					printf("Enter the word to be searched : ");
					scanf("%s", word);
					
					// Calculate hash index based on the first character
					int ind = tolower(word[0]) - 97;
					if(!(ind >= 0 && ind <= 25) )
					{
						ind = 26;  // Index 26 for non-alphabetic entries
					}
					
					// Perform the search and display results
					search(head[ind], word);
					break;
				}
			case 4:
					// Update database by reading data from file
					read_datafile(&fname, head, create_f);
					break;
			case 5:
					// Save the current database to a file
					if(create_f == 1)
					{
						write_databasefile(head);
					}
					else
					{
						printf("Data base is not created !!\n");
						printf("---------SAVE DATABASE FAILED--------\n");
					}
					break;
			case 6:
					return 0; // Exit the program
			default:
					// Handle invalid choice
					printf("Invalid Choice!!\n");
		}
	}
}
