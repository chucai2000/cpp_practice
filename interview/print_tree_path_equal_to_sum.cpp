#include "print_tree_path_equal_to_sum.h"

TEST(print_specific_tree_path, execution)
{
    print_tree_path_equal_to_sum::Node *root_node = new print_tree_path_equal_to_sum::Node(0);
    print_tree_path_equal_to_sum::Node *node1 = new print_tree_path_equal_to_sum::Node(1);
    print_tree_path_equal_to_sum::Node *node2 = new print_tree_path_equal_to_sum::Node(2);
    print_tree_path_equal_to_sum::Node *node3 = new print_tree_path_equal_to_sum::Node(3);
    print_tree_path_equal_to_sum::Node *node4 = new print_tree_path_equal_to_sum::Node(4);
    print_tree_path_equal_to_sum::Node *node5 = new print_tree_path_equal_to_sum::Node(5);
    print_tree_path_equal_to_sum::Node *node6 = new print_tree_path_equal_to_sum::Node(6);

    root_node->left = node1;
    root_node->right = node2;
    node1->right = node3;
    node3->left = node4;
    node2->left = node5;
    node2->right = node6;

    int sum = 8;
    vector<print_tree_path_equal_to_sum::Node*> path;
    print_tree_path_equal_to_sum::print_specific_tree_path(root_node, path, sum);
}
