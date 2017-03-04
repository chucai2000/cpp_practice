#include "common.h"

namespace in_order_successor{

struct Node{
    Node *left;
    Node *right;
    Node *parent;
	int data;

    Node() :left(nullptr), right(nullptr),
            parent(nullptr), data(0)
    {}

    Node(int val) : left(nullptr), right(nullptr),
                    parent(nullptr), data(val)
    {}
};

Node* min_value(Node *input) {
    if (!input) return NULL;
    Node *cur = input;
    while (cur->left) {
        cur = cur->left;
    }
    return cur;
}

// with parent
Node * in_order_successor1(Node *root, Node *n)
{
  // step 1 of the above algorithm 
  if( n->right != NULL )
    return min_value(n->right);
 
  // step 2 of the above algorithm
  struct Node *p = n->parent;
  while(p != NULL && n == p->right)
  {
     n = p;
     p = p->parent;
  }
  return p;
}

// no Parent
Node * in_order_successor2(Node *root, Node *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return min_value(n->right);
 
    Node *succ = NULL;
 
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

}
