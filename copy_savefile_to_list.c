/***************************************************************************************************************************************************
*Author         :Lekhan Gowda R
*Date           :Tue 5 nov 2024 8:06:15 IST
*File           :copy_savefile_to_list.c
*Title          :To generate the tokens.
*Description    :The character string can be tokenized into words . It can be done in the same way, the file is
		:parsed. The non-alphabetic characters can be used as the delimiter.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int copy_savefile_to_list(main_ll *head[], char *savef)
{
	// Declare pointers for main linked list (main_ll) and sub linked list (sub_ll)
	main_ll *mainnode = NULL, *temp1 = NULL, *prev1 = NULL;
	sub_ll *subnode = NULL, *temp2 = NULL, *prev2 = NULL;
	int index, i;
	char ch, str[50];  // Buffer for each string (word or file data) read from file
	
	// Open the specified file in read mode
	FILE *fptr = fopen(savef, "r");
	if (fptr == NULL)
	{
		// If the file doesn't exist, print error message
		printf("File '%s' is not present!!\n", savef);
		return FAILURE;
	}

	// Check if the file is empty
	fseek(fptr, 0, SEEK_END);
	if (ftell(fptr) == 0)
	{
		// Print error if the file is empty
		printf("%s File is Empty!!\n", savef);
		return FAILURE;
	}
	
	// Reset file pointer to the beginning
	fseek(fptr, 0, SEEK_SET);
	
	// Loop to read each word and file data from the file
	while (!feof(fptr) && fscanf(fptr, "%s", str))
	{
		// If the word starts with '#', it represents the index for the main node
		if (str[0] == '#')
		{
			// Convert the index from string to integer
			index = atoi(&str[1]);  //passing the address from 2nd index that will read till null
			                        //although last char is '#' atoi wont take it in the account
		}
		else
		{
			// Process each word entry
			temp1 = head[index];
			mainnode = malloc(sizeof(main_ll));  // Allocate memory for new main node
			if (mainnode == NULL)
				printf("Memory allocation failure\n");
			mainnode->link = NULL;
			mainnode->Tlink = NULL;

			// Tokenize the string to extract word and file count
			char *token;
			int num;
			char delim[] = {":"};
			token = strtok(str, delim);
			if (token != NULL)
			{
				// Extract word and store it in mainnode
				strcpy(mainnode->word, token);
			}
			token = strtok(NULL, delim);
			if (token != NULL)
			{
				// Extract file count and store it in mainnode
				mainnode->file_count = atoi(token);
			}

			// If the list at the index is empty, set the head to the new node
			if (head[index] == NULL)
			{
				head[index] = mainnode;
			}
			else
			{
				// Otherwise, traverse to the last node and add the new node
				while (temp1)
				{
					prev1 = temp1;
					temp1 = temp1->link;
				}
				prev1->link = mainnode;
			}

			// Process each file related to the word in the current mainnode
			for (int i = 0; i < mainnode->file_count; i++)
			{
				// Allocate memory for subnode (file-related data)
				subnode = malloc(sizeof(sub_ll));
				if (subnode == NULL)
					printf("Memory allocation failure\n");
				subnode->table_link = NULL;

				// Tokenize again to extract file name and word count
				token = strtok(NULL, delim);
				if (token != NULL)
				{
					// Extract file name and store in subnode
					strcpy(subnode->file_name, token);
				}
				token = strtok(NULL, delim);
				if (token != NULL)
				{
					// Extract word count and store in subnode
					subnode->word_count = atoi(token);
				}

				// If the sublist (Tlink) is empty, initialize it with the new subnode
				if (mainnode->Tlink == NULL)
				{
					mainnode->Tlink = subnode;
				}
				else
				{
					// Otherwise, traverse the sublist and add the subnode at the end
					temp2 = mainnode->Tlink;
					while (temp2)
					{
						prev2 = temp2;
						temp2 = temp2->table_link;
					}
					prev2->table_link = subnode;
				}
			}
		}
	}	
	
	// Return success after processing the file
	return SUCCESS;
}
