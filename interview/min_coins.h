#include "common.h"
using namespace std;

namespace min_coins {

#define MAXSIZE 1280
static int coin[] = {1, 5, 10, 25};
static int DP[MAXSIZE] = {0};
static int prev_seq[MAXSIZE] = {0};

class Solution {
public:

    int min_coins(int exp_value)
    {
        int i, j, num;
        if (exp_value == 0)
            return 0;

        for (i = 1; i <= exp_value; i++){
            num = 100; // infinite
            for (j = 0; j < 4; j++){
                if (i>=coin[j] && 1+DP[i-coin[j]] < num){
                    num = 1+DP[i-coin[j]];
                    prev_seq[i] = i-coin[j];
                }
            }
            DP[i] = num;
        }

        return num;
    }

    void test_case1()
    {
        int exp_value = 3;
        int minnum = min_coins(exp_value);
        printf("DP = \n");
        for (int i = 0; i <= exp_value; i++){
            printf("%d, ", DP[i]);
        }
        printf("\n the coins are: \n");
        int j = exp_value;
        while (j){
            printf("%d, ", j-prev_seq[j]);
            j = prev_seq[j];
        }
    }

};

}
