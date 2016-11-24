#include <iostream>
using namespace std;

int maxSum(int A[], int n, int *start, int *end)
{
	int maxResult = 0;
	int maxInspect = 0;
	int start_prev; *start = 0; *end = 0;
	
	for (int i = 0; i < n; i++){
		
		if (maxInspect <= 0){
			maxInspect = A[i];
			start_prev = i;
		}
		else{
			maxInspect += A[i];
		}
		
		if (maxInspect > maxResult){
			*end = i;
			*start = start_prev;
		}
		
	}
	
	return maxResult;
}