#include <stdlib.h>

struct node{
	node *left;
	node *right;
	node *parent;
	int data;
};

// with parent
struct node * inOrderSuccessor1(struct node *root, struct node *n)
{
  // step 1 of the above algorithm 
  if( n->right != NULL )
    return minValue(n->right);
 
  // step 2 of the above algorithm
  struct node *p = n->parent;
  while(p != NULL && n == p->right)
  {
     n = p;
     p = p->parent;
  }
  return p;
}

// no Parent
struct node * inOrderSuccessor2(struct node *root, struct node *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return minValue(n->right);
 
    struct node *succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
 
    return succ;
}
