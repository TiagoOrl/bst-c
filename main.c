#include <stdlib.h>
#include <stdio.h>
#include "src/tree.h"


int main(int argc, char const *argv[])
{
    
    
    Tree * tree = newTree();
    
    insert(tree, 30);
    insert(tree, 12);
    insert(tree, 40);
    insert(tree, 22);
    insert(tree, 58);
    insert(tree, 451);
    insert(tree, 3);
    insert(tree, 7);
    insert(tree, 11);
    insert(tree, 35);
    insert(tree, 64);
    insert(tree, 1);


    printf("\n\n\n");

    print(tree, 'p');
    printf("size: %d\n\n", treeSize(tree));
    printf("\n\n");

    delete(tree, 30);
    delete(tree, 8);
    delete(tree, 11);
    delete(tree, 3);
    delete(tree, 64);
    delete(tree, 58);

    print(tree, 'p');
    printf("size: %d\n\n", treeSize(tree));

    printf("\n");
    printf("largest val: (%d)\n", largest(tree));
    printf("minimal val: (%d)\n", minimal(tree));

    return EXIT_SUCCESS;
}
