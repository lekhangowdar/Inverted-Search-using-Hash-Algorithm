/***************************************************************************************************************************************************
*Author         :Lekhan Gowda R
*Date           :Tue 5 nov 2024 8:06:15 IST
*File           :store_word.c
*Title          :To store the words one by one
*Description    :This function process word by word and stores it in the data base.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int store_word(char *word, char *file, main_ll **head)
{
    int i = 0;
    // Convert all characters in the word to lowercase
    while (word[i]) 
    {
        word[i] = tolower((unsigned char)word[i]); // Convert each character
        i++;
    }
    
    // Calculate index based on the first letter (for hash table positioning)
    int ind = word[0] - 97;
    if(!(ind >= 0 && ind <= 25))
    {
        ind = 26; // Index 26 for non-alphabetic entries
    }

    // If the main list at this index is empty, create a new main node
    if(head[ind] == NULL)
    {
        main_ll *new = malloc(sizeof(main_ll));
        if (new == NULL) return FAILURE; // Return if memory allocation fails
        
        head[ind] = new;                 // Set head to the new node
        new->file_count = 1;             // Initialize file count to 1
        new->link = NULL;                // Set main node link to NULL
        
        // Create a sub-node for the first file and link it
        sub_ll *new_sub = malloc(sizeof(sub_ll));
        if (new_sub == NULL) return FAILURE; // Return if memory allocation fails
        
        new->Tlink = new_sub;                // Link sub-node to main node
        strcpy(new->word, word);             // Copy word to main node
        strcpy(new_sub->file_name, file);    // Copy file name to sub-node
        new_sub->table_link = NULL;          // Set sub-node link to NULL
        new_sub->word_count = 1;             // Set word count to 1
        return SUCCESS;
    }

    // Traverse the main list at this index to find the word
    main_ll *temp_m = head[ind];
    while(temp_m)
    {
        // If word matches, check for the file in the sub-nodes
        if (strcmp(temp_m->word, word) == 0)
        {
            sub_ll *temp_s = temp_m->Tlink;
            
            // Traverse sub-nodes to check if file already exists
            while (temp_s)
            {
                if(strcmp(temp_s->file_name, file) == 0)
                {
                    temp_s->word_count++;  // Increment word count if file matches
                    return SUCCESS;
                }
                
                // If at last sub-node, break to add a new one
                if(temp_s->table_link == NULL)
                {
                    break;
                }
                temp_s = temp_s->table_link;
            }
            
            // Create a new sub-node for the file if not found
            sub_ll *new_sub = malloc(sizeof(sub_ll));
            if (new_sub == NULL) return FAILURE; // Return if memory allocation fails
            
            temp_s->table_link = new_sub;       // Link new sub-node
            strcpy(new_sub->file_name, file);   // Copy file name to new sub-node
            new_sub->table_link = NULL;         // Set new sub-node link to NULL
            new_sub->word_count = 1;            // Initialize word count to 1
            temp_m->file_count++;               // Increment file count in main node
            return SUCCESS;
        }
        
        // If at last main node, break to add a new one
        if (temp_m->link == NULL) break;
        temp_m = temp_m->link;
    }

    // Create a new main node for the word if not found in the list
    main_ll *new_main = malloc(sizeof(main_ll));
    if (new_main == NULL) return FAILURE;  // Return if memory allocation fails
    
    strcpy(new_main->word, word);          // Copy word to new main node
    new_main->file_count = 1;              // Initialize file count to 1
    new_main->link = NULL;                 // Set main node link to NULL

    // Create and link the first sub-node for this new main node
    sub_ll *new_sub = malloc(sizeof(sub_ll));
    if (new_sub == NULL) return FAILURE;   // Return if memory allocation fails

    strcpy(new_sub->file_name, file);      // Copy file name to sub-node
    new_sub->table_link = NULL;            // Set sub-node link to NULL
    new_sub->word_count = 1;               // Initialize word count to 1
    new_main->Tlink = new_sub;             // Link sub-node to main node

    temp_m->link = new_main;               // Link the new main node to the list
    return SUCCESS;
}
