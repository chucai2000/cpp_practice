#include "common.h"
using namespace std;

namespace min_coins {

#define MAXSIZE 1280

int min_coins(int exp_value, int *coin)
{
    int DP[MAXSIZE] = {0};
    int prev_seq[MAXSIZE] = {0};

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

    int val = exp_value;
    while (val){
        cout << j-prev_seq[val] << " ";
        val = prev_seq[val];
    }

    return num;
}

}
