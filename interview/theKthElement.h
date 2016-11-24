#include <stdio.h>

int partition(int arr[], int left, int right, int pivot)
{
	while (left <= right){
		while (arr[left] <= pivot)
			left++;
		while(arr[right] > pivot)
			right--;
		if (left < right){
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	return left-1; // return the index of the last element at the left segment
}

int rank(int arr[], int left, int right, int rankToConfirm)
{
	int pivot = (arr[left] + arr[right]) / 2;
	int leftEnd = partition(arr, left, right, pivot); // index of last element
	int leftSize = leftEnd - left + 1;
	if (leftSize == rankToConfirm+1)
		return arr[leftEnd];
	else if (leftSize > rankToConfirm+1)
		return rank(arr, left, leftEnd, rankToConfirm);
	else if (leftSize < rankToConfirm+1)
		return rank(arr, leftEnd+1, right, rankToConfirm-leftSize);
}

int test()
{
	int arr[11] = {16,12,24,8,32,44,40,4,20,28,0};

	int ret = rank(arr, 0, 10, 1);

	printf("%d\n", ret);

	return 0;
}
