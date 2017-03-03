#include "common.h"
using namespace std;

namespace remove_duplicates_from_sorted_list {

struct Node
{
	int value;
	Node *next;
};

void rmv_dup_from_list(Node *list_head)
{
	Node *p = list_head;
	if (p == NULL || p->next == NULL)
		return;
	
	map<int,bool> hash_table;
	hash_table[p->value] = true;
	while(p && p->next){
		if (hash_table.count(p->next->value) != 0){
			p->next = p->next->next;
		}
		else{
			hash_table[p->next->value] = true;
			p = p->next;
		}
	}
}

void rmv_dup_from_sorted_list(Node *list_head)
{
	Node *p = list_head;
	if (p == NULL || p->next == NULL)
		return;
	
	Node *q = p->next;
	while (!p){
		while (q && q->value == p->value){
			q = q->next;
		}
		if (!q)
			return;
		else{
			p->next = q;
			p = q;
			q = q->next;
		}
	}
}

class Solution
{
public:
    void test_case1() {}

};

}
