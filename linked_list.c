#include "inverted_search.h"

int insert_at_last(Flist **head, char* fname)
{
    Flist * new = malloc(sizeof(Flist)); //create a node
    
    //return failure if node is not created
    if( new == NULL)
    {
        return FAILURE;
    }
    
    //update the data and null to new node
    strcpy(new->file_name, fname);
    new->link = NULL;
    
    //check if list is empty and update head with new address
    if( *head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    
    //update head in temp
    Flist *temp = *head;
    
    //traverse to the last
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new; //update last link with new address
}