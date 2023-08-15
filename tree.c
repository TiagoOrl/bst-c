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

    if (found == NULL)
        return false;


    // if leaf node
    if (found->left == NULL && found->right == NULL)
    {
        // find at what side the found node is from parent
        if (found->parent->left != NULL && 
            found->parent->left->id == id)
            found->parent->left = NULL;
        else
            found->parent->right = NULL;
            
            
        free(found);
        return true;
    }

    if (found->left != NULL && found->right == NULL)
    {
        Node * foundParent = found->parent;
        found->left->parent = foundParent;

        // find at what side the found node is from parent
        if (foundParent->left != NULL && foundParent->left->id == id)
            foundParent->left = found->left;
        else
            foundParent->right = found->left;
        
        free(found);
        return true;
    }

    if (found->right != NULL && found->left == NULL)
    {
        Node * foundParent = found->parent;
        found->right->parent = foundParent;

        // find at what side the found node is from parent
        if (foundParent->left != NULL && foundParent->left->id == id)
            foundParent->left = found->right;
        else
            foundParent->right = found->right;
        
        free(found);
        return true;
    }

    if (found->left != NULL && found->right != NULL)
    {
        Node * succ = found->right;
        Node * foundParent = found->parent;


        if (succ->left != NULL)
        {
            while (succ->left != NULL)
            {
                succ = succ->left;
            }

            if (succ->right != NULL)
            {
                succ->parent->left = succ->right;
                succ->right->parent = succ->parent;
            }
            else
                succ->parent->left = NULL;
        } 
        
        else 
        {
            succ = found->left;
            if (succ->right == NULL)
            {
                succ->parent->left = NULL;
            }
            else 
            {
                while (succ->right != NULL)
                {
                    succ = succ->right;
                }
                
                if (succ->left != NULL)
                {
                    succ->parent->right = succ->left;
                    succ->left->parent = succ->parent;
                }
                else
                    succ->parent->right = NULL;
            }
        }


        found->id = succ->id;

        free(succ);
        return true;
    }

    return true;
}

int size(Node * node)
{
    if (node == NULL)
        return 0;

    return (size(node->left) + 1 + size(node->right));
}

void printAll(Node * node, const char side)
{
    if (node == NULL)
        return;

    printf("%c node (%d), h = %d", side, node->id, node->height);
    
    if (node->parent != NULL)
        printf("\tpar. -> (%d) \n", node->parent->id);
    else
        printf("\t(root)\n");

    printAll(node->left, '<');
    printAll(node->right, '>');
    
}

void printInOrder(Node * node, const char side)
{
    if (node == NULL)
        return;

    printInOrder(node->left, '<');
    printf("%c node (%d)", side, node->id);
    if (node->parent != NULL)
        printf("\tpar (%d)\n", node->parent->id);
    else
        printf("\t(root)\n");
    printInOrder(node->right, '>');
}