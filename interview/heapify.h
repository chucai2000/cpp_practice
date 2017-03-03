#include "common.h"
using namespace std;

namespace heapify {
    
void heapify(int A[], int size, int i) {

    int j = i, k = i;

    while (2*j+1 < size) {

        if (A[2*j+1] > A[j])
            k = 2*j+1;
        if (2*j+2<size && A[2*j+2] > A[k])
            k = 2*j+2;

        if (k==j)
            break;
        else {
            int temp = A[j];
            A[j] = A[k];
            A[k] = temp;
            j = k;
        }

    }

}

void build_heap(int A[], int size) {
    for (int i = (size-1)/2; i >= 0; i--)
        heapify(A, size, i);
}

class Solution
{
public:
    void test_case1() {
        int A[] = {5, 4, 1, 0, -2, 15, 8, 4, 9, 7, 21};
        build_heap(A, 11);
        for (int i = 0; i < 11; i ++) {
            cout << A[i] << " ";
        }
        printf("\n");
    }
};

}
