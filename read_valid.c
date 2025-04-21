#include "inverted_search.h"


// Function: read_validate
// Purpose: Validates the input files provided through command-line arguments,
//          checks if they are empty, and inserts valid files into a linked list.

int read_validate(char* argv[], int argc, Flist **fname)
{
    // Check if the number of arguments is less than 2 (indicating no file is provided)
    if (argc < 2)
    {
        // Print an error message if no file is provided
        printf("Invalid arguments. Enter file name\n");
        return FAILURE;
    }
    else
    {
        // Iterate over each file argument passed to the program
        FILE *fptr;
        for (int i = 1; i < argc; i++)
        {
            // Try opening the file in read mode
            if ((fptr = fopen(argv[i], "r")) != NULL)
            {
                // Move the file pointer to the end of the file to check its size
                fseek(fptr, 0, SEEK_END);
                
                // Check if the file is empty
                if (ftell(fptr) == 0)
                {
                    // Print a message indicating that the file is empty
                    printf("%s File is Empty", argv[i]);
                    continue;  // Skip to the next file if empty
                }
                
                // If the file is non-empty, insert it into the file list
                insert_at_last(fname, argv[i]);
                
                // Print success message for the current file
                printf("%s SUCCESS\n", argv[i]);
                
                // Close the file after processing
                fclose(fptr);
            }
            else
            {
                // Print failure message if the file could not be opened
                printf("%s FAILURE\n", argv[i]);
            }
        }
    }

    // Check if no valid files have been added to the list
    if (*fname == NULL)
    {
        // Print a message if no files were valid
        printf("No files are present\n");
        return 0;  // Return 0 indicating no files were successfully added
    }

    return SUCCESS;  // Return success if files were validated and added
}
