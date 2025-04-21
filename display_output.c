/***************************************************************************************************************************************************
*Author         :Lekhan Gowda R
*Date           :Tue 5 nov 2024 8:06:15 IST
*File           :display_output.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
****************************************************************************************************************************************************/
#include "inverted_Search.h"

void display_database(main_ll *head[])
{
	printf("\n----------------------------DISPLAYING DATABASE--------------------------------\n");
	printf("[Index]\t [Word]\t\tFilecount\tFile name   Word_count\n");

	int i;
	// Iterate through each index in the hash table (27 slots)
	for(i = 0; i < 27; i++)
	{
		main_ll *head_m = head[i]; // Pointer to the main linked list at the current index
		
		// Traverse through the main linked list at the current index
		while(head_m != NULL && head_m->file_count != 0)
		{
			// Print index, word, and the file count for the current main node
			printf(" [%d]\t[%-8s]\t  %d\t", i, head_m->word, head_m->file_count);

			sub_ll *Thead = head_m->Tlink; // Pointer to the sub linked list

			// Traverse the sub linked list to print file name and word count
			while(Thead)
			{
				// Print file name and the word count in that file
				printf("\t%-8s\t%d", Thead->file_name, Thead->word_count);
				Thead = Thead->table_link; // Move to the next file in sub linked list
			}

			// Print a new line for the next main node entry
			printf("\n");

			head_m = head_m->link; // Move to the next word in the main linked list
		}
	}
	printf("-------------------------------------------------------------------------------\n");
}
