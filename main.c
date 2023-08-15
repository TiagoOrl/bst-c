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
    insert(root, NULL, 58);
    root = insert(root, NULL, 47);
    root = insert(root, NULL, 3);
    root = insert(root, NULL, 7);
    root = insert(root, NULL, 11);
    root = insert(root, NULL, 35);
    insert(root, NULL, 64);


    printf("\n\n\n");

    printAll(root, '|');
    printf("size: %d\n\n", size(root));
    printf("\n\n");

    delete(root, 30);
    delete(root, 8);
    delete(root, 11);

    printAll(root, '|');
    printf("size: %d\n\n", size(root));

    return EXIT_SUCCESS;
}
