#include <stdio.h>
#include <stdlib.h>


typedef int datatype;

typedef struct node 
{
    datatype data;

    int height;
    struct node *lchild;
    struct node *rchild;

}treenode,*linktree;

linktree newNode(datatype data);

linktree avlInsert(linktree root,linktree new);

linktree avlRotateRight(linktree root);

linktree avlRotateLeft(linktree root);

linktree avlRotateLeftRight(linktree root);

linktree avlRotateRightLeft(linktree root);


#define MAX(a, b) ({ \
		typeof(a) _a = a; \
		typeof(b) _b = b; \
		(void)(&_a == &_b);\
		_a > _b? _a : _b; \
		})


static datatype height(linktree root)
{
    return root == NULL ? 0 : root->height;
}
