#include <stdlib.h>
#include <stdio.h>
#include "src/tree.h"


int main(int argc, char const *argv[])
{
    
    
    Tree * tree = newTree();
    
    insert(tree, 2);
    insert(tree, 10);
    insert(tree, 30);
    insert(tree, -31);
    insert(tree, -33);
    insert(tree, 22);


    printf("\n\n\n");

    print(tree, 'p');
    printf("size: %d\n\n", treeSize(tree));
    printf("\n\n");

    // delete(tree, 30);
    // delete(tree, 8);
    // delete(tree, 11);
    // delete(tree, 3);
    // delete(tree, 64);
    // delete(tree, 58);

    // print(tree, 'p');
    // printf("size: %d\n\n", treeSize(tree));

    printf("\n");
    printf("largest val: (%d)\n", largest(tree));
    printf("minimal val: (%d)\n", minimal(tree));

    return EXIT_SUCCESS;
}
