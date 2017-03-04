#include "common.h"
using namespace std;

namespace print_tree_path_equal_to_sum {

struct Node
{
	int value;
	Node *left;
	Node *right;

    Node(): value(0), left(nullptr), right(nullptr)
    {}

    Node(int val): value(val), left(nullptr), right(nullptr)
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

void print_specific_tree_path(Node *node, vector<Node*> &path, int &sum)
{
    if (node == NULL)
        return;

    path.push_back(node);
    sum -= node->value;
    if (node->left==NULL && node->right==NULL && sum==0){
        // output path
        for (Node* const & cur : path) {
            std::cout << cur->value << " " << std::endl;
        }
        std::cout << "#" << std::endl;
    }

    print_specific_tree_path(node->left, path, sum);
    print_specific_tree_path(node->right, path, sum);

    sum += node->value;
    path.pop_back();

    return;
}

}
