#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/db_io.h"


Node* read_full_collection(char *collection_name) {
    char db_path[128] = "./db/";

    if (strlen(db_path) + strlen(collection_name) + 1 >= sizeof(db_path))
    {
        fprintf(stderr, "Error: read_fell_collection()\n Path to the collection exceeds the buffer size.\n");
        return NULL;
    }

    // Concatenate the collection name to the db_path
    strcat(db_path, collection_name);
    
    // Read the file
    FILE *pF = fopen(db_path, "r");
    if (pF == NULL)
    {
        fprintf(stderr,"Unable to open file: %s!\n", db_path);
        return NULL;
    }

    char *buffer = NULL;
    size_t len = 0;
    char temp[255];
    while (fgets(temp, sizeof(temp), pF))
    {
        size_t tempLen = strlen(temp);

        char *bufferUpdate = realloc(buffer, len + tempLen + 1);
        if (bufferUpdate == NULL)
        {
            perror("Failed to reallocate memory during file reading");
            free(buffer);
            return NULL;
        }
        buffer = bufferUpdate;

        strcpy(buffer + len, temp);
        len += tempLen;
    }
    // Close the file
    fclose(pF);

    if (buffer != NULL)
    {
        printf("%s", buffer);
        free(buffer);
    }

    Node *new_node = NULL;
    return new_node;
}