#include <map>
using namespace std;

struct Node
{
	int value;
	Node *next;
};

void RmvDupFromList(Node *listHead)
{
	Node *p = listHead;
	if (p == NULL || p->next == NULL)
		return;
	
	map<int,bool> hashTable;
	hashTable[p->value] = true;
	while(p && p->next){
		if (hashTable.count(p->next->value) != 0){
			p->next = p->next->next;
		}
		else{
			hashTable[p->next->value] = true;
			p = p->next;
		}
	}
}

void RmvDupFromSortedList(Node *listHead)
{
	Node *p = listHead;
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

