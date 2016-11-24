#include <vector>
using namespace std;

struct Node
{
	int value;
	Node *left;
	Node *right;
};

void printSpecificTreePath(Node *node, vector<Node*> &path, int &sum)
{
	if (node == NULL)
		return;
	
	path.push_back(node);
	sum -= node->value;
	if (node->left==NULL && node->right==NULL && sum==0){
		// output path
	}
	
	printSpecificTreePath(node->left, path, sum);
	printSpecificTreePath(node->right, path, sum);
	
	sum += node->value;
	path.pop_back();
	
	return;
}

void mainFunc(Node *rootNode, int sum)
{
	vector<Node*> path;
	printSpecificTreePath(rootNode, path, sum);
}
