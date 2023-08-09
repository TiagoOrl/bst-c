#include <stdlib.h>
#include <stdio.h>

struct _node
{
    int id;
    int height;
    struct _node * left;
    struct _node * right;
    struct _node * parent;
};

typedef struct _node Node;

Node * createOne(int id);

int max(int a, int b);

int height(Node * n);

Node * createRoot(int id);

Node * insert(Node * node, Node * parent, int id);

void printAll(Node * node, const char side);
