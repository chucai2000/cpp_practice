#include "remove_duplicates_from_sorted_list.h"

TEST(remove_duplicates_from_sorted_list, execution)
{
    remove_duplicates_from_sorted_list::Node *node0 =
            new remove_duplicates_from_sorted_list::Node(0);
    remove_duplicates_from_sorted_list::Node *node1 =
            new remove_duplicates_from_sorted_list::Node(0);
    remove_duplicates_from_sorted_list::Node *node2 =
            new remove_duplicates_from_sorted_list::Node(1);
    remove_duplicates_from_sorted_list::Node *node3 =
            new remove_duplicates_from_sorted_list::Node(1);
    remove_duplicates_from_sorted_list::Node *node4 =
            new remove_duplicates_from_sorted_list::Node(2);
    remove_duplicates_from_sorted_list::Node *node5 =
            new remove_duplicates_from_sorted_list::Node(4);
    remove_duplicates_from_sorted_list::Node *node6 =
            new remove_duplicates_from_sorted_list::Node(4);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    remove_duplicates_from_sorted_list::rmv_dup_from_sorted_list(node0);
    remove_duplicates_from_sorted_list::Node *cur = node0;
    while (cur) {
        std::cout << cur->value << std::endl;
        cur = cur->next;
    }
}
