#include "tree.h"

Node * createNode(int id)
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

Tree * newTree()
{
    Tree * tree = (Tree *)malloc(sizeof(Tree));
    tree->min = 0;
    tree->max = 0;
    tree->root = NULL;
    tree->size = 0;

    return tree;
}

Node * rightRotate(Node * y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;

    y->parent = x;
    if (T2 != NULL)
        T2->parent = y;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Return new root
    return x;
}
 

Node * leftRotate(Node * x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;

    x->parent = y;
    if (T2 != NULL)
        T2->parent = x;
 
    // Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


Node * balanceNode(Node * node, int id)
{
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && id < node->left->id)
    {
        printf("node %d unbalanced - left left\n", node->id);
        return rightRotate(node);
    }
        
 
    // Right Right Case
    if (balance < -1 && id > node->right->id) 
    {
        printf("node %d unbalanced - right right\n", node->id);
        return leftRotate(node);
    }
        
 
    // Left Right Case
    if (balance > 1 && id > node->left->id)
    {
        printf("node %d unbalanced - left right\n", node->id);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && id < node->right->id)
    {
        printf("node %d unbalanced - right left\n", node->id);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return NULL;
}


Node * insertInNode(Node * node, Node * parent, int id)
{
    if (node == NULL) {
        node = createNode(id);
        node->parent = parent;
        printf("%d inserted\n", id);
        
        return node;
    }
        
    if (id < node->id) {
        printf("< of (%d) \n", node->id);
        node->left = insertInNode(node->left, node, id);
    }
        
    else if (id > node->id) {
        printf("> of (%d) \n", node->id);
        node->right = insertInNode(node->right, node, id);
    }

    else 
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    Node * balanced = balanceNode(node, id);

    if (balanced != NULL)
        return balanced;

    printf("unstack insert(%d), h = %d\n", node->id, node->height);

    return node;
}

void insert(Tree * tree, int id)
{
    tree->root = insertInNode(tree->root, NULL, id);
}

Node * searchInNode(Node * node, int id, bool debug)
{
    if (node == NULL)
        return NULL;

    if (node->id == id)
        return node;

    if (id < node->id)
    {
        if (debug == true)
            printf("< %d\n", node->id);
        return searchInNode(node->left, id, debug);
    }

    if (debug == true)
        printf("> %d\n", node->id);
    return searchInNode(node->right, id, debug);
}

Node * search(Tree * tree, int id, bool debug)
{
    searchInNode(tree->root, id, debug);
}

bool delete(Tree * tree, int id)
{
    Node * found = search(tree, id, false);
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

int treeSize(Tree * tree)
{
    tree->size = size(tree->root);
    return tree->size;
}

int nodeMinimal(Node * node)
{
    if (node->left != NULL)
        return nodeMinimal(node->left);

    return node->id;
}

int minimal(Tree * tree)
{
    tree->min = nodeMinimal(tree->root);
    return tree->min;
}

int nodeLargest(Node * node)
{
    if (node->right != NULL)
        return nodeLargest(node->right);

    return node->id;
}

int largest(Tree * tree)
{
    tree->max = nodeLargest(tree->root);
    return tree->max;
}

void printPre(Node * node, const char side)
{
    if (node == NULL)
        return;

    printf("%c node (%d), h = %d", side, node->id, node->height);
    
    if (node->parent != NULL)
        printf("\tpar. -> (%d) \n", node->parent->id);
    else
        printf("\t(root)\n");

    printPre(node->left, '<');
    printPre(node->right, '>');
    
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

void print(Tree * tree, const char traversal)
{
    if (traversal == 'i')
        printInOrder(tree->root, '|');

    if (traversal == 'p')
        printPre(tree->root, '|');
}