#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


int main(int argc, char const *argv[])
{
    
    
    Node * root = createRoot(8);
    
    root = insert(root, NULL, 30);
    root = insert(root, NULL, 12);
    root = insert(root, NULL, 40);
    root = insert(root, NULL, 22);
    root = insert(root, NULL, 36);

    root = insert(root, NULL, 58);
    root = insert(root, NULL, 3);
    root = insert(root, NULL, 7);
    

    printf("\n\n\n");

    printAll(root, '|');

    printf("\n\n\n");

    int id = 22;
    Node * found = search(root, id, true);

    if (found != NULL)
        printf("found node %d\n", found->id);
    else
        printf("node %d not found\n", id);

    


    return 0;
}
