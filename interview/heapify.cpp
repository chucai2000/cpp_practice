#include "heapify.h"

TEST(heapify, execution)
{
    int A[] = {5, 4, 1, 0, -2, 15, 8, 4, 9, 7, 21};
    heapify::build_heap(A, 11);
    for (int i = 0; i < 11; i ++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
