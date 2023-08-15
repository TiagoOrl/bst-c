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

    root = insert(root, NULL, 47);
    root = insert(root, NULL, 3);
    root = insert(root, NULL, 7);
    root = insert(root, NULL, 11);
    root = insert(root, NULL, 35);


    printf("\n\n\n");
    delete(root, 8);
    delete(root, 3);
    delete(root, 40);

    printInOrder(root, '|');

    return 0;
}
