#include <stdio.h>

#include "../include/db_io.h"

int main() {

    Node *new_node = read_full_collection("data.json");
    
    if (new_node == NULL)
    {
        return 1;
    }
    

    return 0;
}
