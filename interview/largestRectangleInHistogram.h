#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

#define MAX(a,b) ((a)>=(b)?(a):(b))

int largestRectangleArea(vector<int> &height)
{
	stack<int> s;
	height.push_back(0);
	int result = 0;
	for (int i = 0; i < height.size();){
		if (s.empty() || height[i]>height[s.top()])
			s.push(i++);
		else{
			int tmp = s.top();
			s.pop();
			result = MAX(result, height[tmp]*(s.empty()?i:i-s.top()-1));
		}
	}
	return result;
}

int test()
{
	vector<int> height;
	height.push_back(2);
	height.push_back(4);
	height.push_back(5);
	height.push_back(6);
	height.push_back(7);
	height.push_back(3);

	int result = largestRectangleArea(height);

	return 0;
}