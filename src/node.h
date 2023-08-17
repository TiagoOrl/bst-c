

struct _node
{
    int id;
    int height;
    struct _node * left;
    struct _node * right;
    struct _node * parent;
};

typedef struct _node Node;