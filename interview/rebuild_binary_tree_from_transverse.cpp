#include "rebuild_binary_tree_from_transverse.h"

TEST(build_inorder_postorder, execution)
{
    int preorder[] = {0, 1, 5, 2, 4, 9};
    int inorder[] = {1, 5, 0, 4, 2, 9};
    rebuild_binary_tree_from_transverse::map_to_indices(inorder, 6);
    rebuild_binary_tree_from_transverse::Node *root_node =
            rebuild_binary_tree_from_transverse::build_inorder_preorder(inorder, preorder, 6, 0);
    EXPECT_EQ(root_node->left->val, 1);
    EXPECT_EQ(root_node->right->val, 2);
    EXPECT_EQ(root_node->left->right->val, 5);
    EXPECT_EQ(root_node->right->right->val, 9);
}
