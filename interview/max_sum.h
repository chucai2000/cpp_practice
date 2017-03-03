#include "common.h"
using namespace std;

namespace max_sum {

class Solution {

    int max_sum(int A[], int n, int *start, int *end)
    {
        int max_result = 0;
        int max_inspect = 0;
        int start_prev; *start = 0; *end = 0;

        for (int i = 0; i < n; i++){

            if (max_inspect <= 0){
                max_inspect = A[i];
                start_prev = i;
            }
            else{
                max_inspect += A[i];
            }

            if (max_inspect > max_result){
                *end = i;
                *start = start_prev;
            }

        }

        return max_result;
    }

public:
    void test_case1() {

    }

};

}
