#include <stdlib.h>
#include <stdio.h>
#include "node.h"

#define true 1
#define false 0

typedef int bool;

struct _tree {
    Node * root;
    int max;
    int min;
    int size;
};

typedef struct _tree Tree;

Tree * newTree();

Node * createNode(int id);

int max(int a, int b);

int height(Node * node);

Node * insertInNode(Node * node, Node * parent, int id);

void insert(Tree *, int id);

Node * searchInNode(Node * node, int id, bool debug);

Node * search(Tree * tree, int id, bool debug);

bool delete(Tree * tree, int id);

int size(Node * n);

int treeSize(Tree * t);

int minimal(Tree * tree);

int nodeMinimal(Node * node);

int largest(Tree * tree);

int nodeLargest(Node * n);

void print(Tree * tree, const char t);

void printPre(Node * n, const char side);

void printInOrder(Node * n, const char side);

int getBalance(Node * n);

Node * rightRotate(Node * node);

Node * leftRotate(Node * node);

Node * balanceNode(Node * node, int id);
