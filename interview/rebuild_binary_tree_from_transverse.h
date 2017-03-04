#include "common.h"

namespace rebuild_binary_tree_from_transverse {

struct Node{
    int val;
    Node *left;
    Node *right;

    Node(): val(0), left(nullptr), right(nullptr)
    {}

    Node(int val): val(val), left(nullptr), right(nullptr)
    {}

    ~Node() {
        if (!left) {
            delete left;
            left = nullptr;
        }
        if (!right) {
            delete right;
            right = nullptr;
        }
    }
};

const int MAX = 256;
// a fast lookup for inorder's element -> index
// binary tree's element must be in the range of [0, MAX-1]
int map_index[MAX];
void map_to_indices(int inorder[], int n) {
  for (int i = 0; i < n; i++) {
    assert(0 <= inorder[i] && inorder[i] <= MAX-1);
    map_index[inorder[i]] = i;
  }
}

// precondition: map_to_indices must be called before entry
Node *build_inorder_preorder(int in[], int pre[], int n, int offset) {
  assert(n >= 0);
  if (n == 0) return NULL;
  int root_val = pre[0];
  int i = map_index[root_val]-offset;  // the divider's index
  Node *root = new Node(root_val);
  root->left = build_inorder_preorder(in, pre+1, i, offset);
  root->right = build_inorder_preorder(in+i+1, pre+i+1, n-i-1, offset+i+1);
  return root;
}


Node *build_inorder_postorder(int in[], int post[], int n, int offset) {
  assert(n >= 0);
  if (n == 0) return NULL;
  int root_val = post[n-1];
  int i = map_index[root_val]-offset;  // the divider's index
  Node *root = new Node(root_val);
  root->left = build_inorder_postorder(in, post, i, offset);
  root->right = build_inorder_postorder(in+i+1, post+i, n-i-1, offset+i+1);
  return root;
}

}
