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

    root = insert(root, NULL, 58);
    root = insert(root, NULL, 64);
    root = insert(root, NULL, 3);
    root = insert(root, NULL, 7);

    printf("\n\n\n");

    printAll(root, '|');
    printf("\n\n\n");

    delete(root, 58);
    printAll(root, '|');


    return 0;
}
