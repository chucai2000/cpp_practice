#include <stdio.h>

namespace the_kth_element {

class Solution {
public:

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

    int rank(int arr[], int left, int right, int rank_to_confirm)
    {
        int pivot = (arr[left] + arr[right]) / 2;
        int left_end = partition(arr, left, right, pivot); // index of last element
        int left_size = left_end - left + 1;
        if (left_size == rank_to_confirm+1)
            return arr[left_end];
        else if (left_size > rank_to_confirm+1)
            return rank(arr, left, left_end, rank_to_confirm);
        else if (left_size < rank_to_confirm+1)
            return rank(arr, left_end+1, right, rank_to_confirm-left_size);
    }

    int test_case1()
    {
        int arr[11] = {16,12,24,8,32,44,40,4,20,28,0};

        int ret = rank(arr, 0, 10, 1);

        printf("%d\n", ret);

        return 0;
    }

};

}
