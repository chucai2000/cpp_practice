#include "common.h"
using namespace std;

namespace print_tree_path_equal_to_sum {

struct Node
{
	int value;
	Node *left;
	Node *right;
};

class Solution {

    void print_specific_tree_path(Node *node, vector<Node*> &path, int &sum)
    {
        if (node == NULL)
            return;

        path.push_back(node);
        sum -= node->value;
        if (node->left==NULL && node->right==NULL && sum==0){
            // output path
        }

        print_specific_tree_path(node->left, path, sum);
        print_specific_tree_path(node->right, path, sum);

        sum += node->value;
        path.pop_back();

        return;
    }

    void main_func(Node *root_node, int sum)
    {
        vector<Node*> path;
        print_specific_tree_path(root_node, path, sum);
    }

public:
    void test_case1() {

    }

};

}
