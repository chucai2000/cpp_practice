#include "in_order_successor.h"

TEST(in_order_successor, execution)
{
    std::unique_ptr<in_order_successor::Node> root(new in_order_successor::Node(0));
    std::unique_ptr<in_order_successor::Node> node1(new in_order_successor::Node(1));
    std::unique_ptr<in_order_successor::Node> node2(new in_order_successor::Node(2));
    root->left = node1.get();
    root->right = node2.get();
    node1->parent = root.get();
    node2->parent = root.get();

    std::unique_ptr<in_order_successor::Node> node3(new in_order_successor::Node(3));
    std::unique_ptr<in_order_successor::Node> node4(new in_order_successor::Node(4));
    node1->right = node3.get();
    node3->parent = node1.get();
    node2->left = node4.get();
    node4->parent = node2.get();

    std::unique_ptr<in_order_successor::Node> node5(new in_order_successor::Node(5));
    node4->right = node5.get();
    node5->parent = node4.get();

    in_order_successor::Node *res = in_order_successor1(root.get(), node3.get());
    EXPECT_EQ(res->data, 0);
}
