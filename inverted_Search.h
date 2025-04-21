
#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//defining macros
#define FAILURE   -1
#define SUCCESS    0

//Structure for file list
typedef struct file_node
{
	char file_name[50];         // Holds the name of the file
	struct file_node *link;     // Pointer to the next file node

} Flist;

//Structure for link table
typedef struct sub_node
{
	int word_count;             // Number of occurrences of the word in the file
	char file_name[50];         // Name of the file containing the word
	struct sub_node *table_link; // Link to the next sub_node (same word in another file)
} sub_ll;

//structure to store word count
typedef struct main_node
{
	int file_count;             // Number of files containing the word
	char word[50];              // Unique word in the database
	sub_ll *Tlink;              // Link to the first sub_node for this word
	struct main_node *link;     // Link to the next main_node (next unique word)
} main_ll;

//declaring all the function defination of this project
//  Validates and reads the file names provided as arguments.
int read_validate(char* argv[], int argc, Flist **fname);

//  Inserts a new file name at the end of the linked list.
int insert_at_last(Flist **head, char *fname);

//  Creates an inverted index database from the files provided.
int create_database(Flist *fname, main_ll **head);

//  Adds a word occurrence from a file into the main linked list.
int store_word(char *name, char *file, main_ll **head);

//  Displays the entire database with each word and file occurrence.
void display_database(main_ll *head[]);

//  Searches for a specific word within the database.
int search(main_ll *head,char *word);

//  Writes the database content to a file for persistent storage.
void write_databasefile(main_ll *head[]);

//  Reads data from a file to create or update the database.
void read_datafile(Flist **file, main_ll* head[], unsigned int create_f);

#endif

