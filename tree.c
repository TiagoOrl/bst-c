#include "tree.h"

Node * createOne(int id)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->height = 1;

    return newNode;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(Node * n)
{
    if (n == NULL)
        return 0;
    
    return n->height;
}

Node * createRoot(int id)
{
    return createOne(id);
}


Node * insert(Node * node, Node * parent, int id)
{

    if (node == NULL) {
        node = createOne(id);
        node->parent = parent;
        printf("%d inserted\n", id);
        
        return node;
    }
        
    if (id < node->id) {
        printf("< of (%d) \n", node->id);
        node->left = insert(node->left, node, id);
    }
        
    else if (id > node->id) {
        printf("> of (%d) \n", node->id);
        node->right = insert(node->right, node, id);
    }

    else 
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    
    printf("unstack insert(%d), h = %d\n", node->id, node->height);

    return node;
}

Node * search(Node * root, int id, bool debug)
{
    if (root == NULL)
        return NULL;

    if (root->id == id)
        return root;

    if (id < root->id)
    {
        if (debug == true)
            printf("< %d\n", root->id);
        return search(root->left, id, debug);
    }

    if (debug == true)
        printf("> %d\n", root->id);
    return search(root->right, id, debug);
}

bool delete(Node * root, int id)
{
    Node * found = search(root, id, false);


}

void printAll(Node * node, const char side)
{
    if (node != NULL)
    {
        printf("%c node (%d), \t height %d ", side, node->id, node->height);
        
        if (node->parent != NULL)
            printf("parent : (%d) \n", node->parent->id);
        else
            printf("(root)\n");

        printAll(node->left, '<');
        printAll(node->right, '>');
    }
}