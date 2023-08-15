#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

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

Node * search(Node * root, int id, bool debug);

bool delete(Node * root, int id);

void printAll(Node * node, const char side);

void printInOrder(Node * node, const char side);
