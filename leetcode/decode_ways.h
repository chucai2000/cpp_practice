#ifndef DECODE_WAYS_H
#define DECODE_WAYS_H

#include "common.h"
using namespace std;

class Solution {
public:

    bool decodeable(string s) {
        if (s.size() == 0 || s.size() > 2) return false;
        if (s.size() == 2 && s[0] == '0') return false;
        int num = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (!(s[i] >= '0' && s[i] <= '9')) return false;
            num = num * 10 + (s[i]-'0');
        }
        return (num>=1 && num<=26);
    }

    int numDecodings(string s) {

        vector<int> dp(s.size()+1, 0);

        dp[0] = 1;
        dp[1] = decodeable(s.substr(0,1)) ? 1 : 0;

        for (size_t i = 2; i < dp.size(); ++i) {

            /// dp[i] cares how many decode ways at s[0 .. i-1]
            string piece2 = s.substr(i-2,2);
            string piece1 = s.substr(i-1,1);
            if (decodeable(piece2) && decodeable(piece1)) {
                dp[i] = dp[i-2] + dp[i-1];
            }
            else if (decodeable(piece1)) {
                dp[i] = dp[i-1];
            }
            else if (decodeable(piece2)) {
                dp[i] = dp[i-2];
            }
            else {
                dp[i] = 0;
            }
        }

        return dp.back();
    }

    void test_case1() {
        string s("213");
        int result = numDecodings(s);
        cout << "result = " << result << endl;
    }
};

#endif
