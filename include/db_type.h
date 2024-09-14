#ifndef DB_TYPES_H
#define DB_TYPES_H


typedef struct Node
{
    char *key;
    char *value;
    struct Node *next;
} Node;


#endif