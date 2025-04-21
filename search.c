/***************************************************************************************************************************************************
*Author         :Lekhan Gowda R
*Date           :Tue 5 nov 2024 8:06:15 IST
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
****************************************************************************************************************************************************/
#include "inverted_Search.h"

int search(main_ll *head, char *word)
{	
	// Check if the list is empty at the specified index
	if(head == NULL)
	{
		printf("Search failed, list is empty\n");
		return 1;
	}

	// Traverse the main linked list to find the word
	while(head)
	{
		// Compare the current word with the target word
		if(strcmp(head->word, word) == 0)
		{
			// Word is found, display file count
			printf("Word '%s' is present in %d file/s\n", word, head->file_count);
			sub_ll *Thead = head->Tlink; // Pointer to traverse the sub linked list

			// Traverse the sub linked list to display each file and count
			while(Thead)
			{
				// Print file name and the count of occurrences in that file
				printf("-> In file: '%s'  %d time/s\n", Thead->file_name, Thead->word_count);
				Thead = Thead->table_link; // Move to the next file in the sub linked list
			}
			printf("\n");
			return 1; // Return after displaying all occurrences
		}
		head = head->link; // Move to the next main node if word is not found in the current one
	}

	// If the word is not found, print a message
	printf("Search word is not present\n");
}
