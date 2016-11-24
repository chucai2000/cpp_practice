#ifndef LVP_H
#define LVP_H

#include "common.h"
using namespace std;

class Solution {
public:

    int lvp(string s) {

        if (s.length() == 0) return 0;
        //s.push_back('(');

        int lastInvalid = -1;
        stack<int> stk;
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            /*if (stk.empty() && s[i] == ')') {
                len = (i - lastInvalid - 1 > len) ? i - lastInvalid - 1 : len;
                lastInvalid = i;
            }*/
            if (stk.empty()) {
                len = (i - lastInvalid - 1 > len) ? i - lastInvalid - 1 : len;
                if (s[i] == ')') lastInvalid = i;
            }

            if (s[i] == '(') {
                stk.push(i);
            }
            else if (!stk.empty() && s[i] == ')') {
                len = (i-stk.top()+1 > len) ? i-stk.top()+1 : len;
                stk.pop();
            }
        }

        /*int stackBottom = -1;
        while (!stk.empty()) {
            stackBottom = stk.top();
            stk.pop();
        }
        len = (stackBottom - lastInvalid - 1 > len) ? stackBottom - lastInvalid - 1 : len;*/
        if (stk.empty()) {
            len = (s.length() - lastInvalid - 1 > len) ? s.length() - lastInvalid - 1: len;
        }

        return len;
    }

    int longestValidParentheses(string s) {
        int len1 = lvp(s);
        cout << "len1 = " << len1 << endl;
        string sRev; sRev.resize(s.length());
        reverse_copy(s.begin(), s.end(), sRev.begin());
        for (int i = 0; i < sRev.length(); i++) {
            if (sRev[i] == '(') sRev[i] = ')';
            else if (sRev[i] == ')') sRev[i] = '(';
        }
        int len2 = lvp(sRev);
        cout << "len2 = " << len2 << endl;
        return (len1<len2) ? len2 : len1;
    }

    void test_case1() {
        std::string str = "()()";
        int len = longestValidParentheses(str);
        printf("len=%d\n", len);
    }
};

#endif
