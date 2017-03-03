#include "common.h"
using namespace std;

namespace longest_valid_parenthese {

class Solution {
public:

    int lvp(string s) {

        if (s.length() == 0) return 0;
        //s.push_back('(');

        int last_invalid = -1;
        stack<int> stk;
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            /*if (stk.empty() && s[i] == ')') {
                len = (i - last_invalid - 1 > len) ? i - last_invalid - 1 : len;
                last_invalid = i;
            }*/
            if (stk.empty()) {
                len = (i - last_invalid - 1 > len) ? i - last_invalid - 1 : len;
                if (s[i] == ')') last_invalid = i;
            }

            if (s[i] == '(') {
                stk.push(i);
            }
            else if (!stk.empty() && s[i] == ')') {
                len = (i-stk.top()+1 > len) ? i-stk.top()+1 : len;
                stk.pop();
            }
        }

        /*int stack_bottom = -1;
        while (!stk.empty()) {
            stack_bottom = stk.top();
            stk.pop();
        }
        len = (stack_bottom - last_invalid - 1 > len) ? stack_bottom - last_invalid - 1 : len;*/
        if (stk.empty()) {
            len = (s.length() - last_invalid - 1 > len) ? s.length() - last_invalid - 1: len;
        }

        return len;
    }

    int longest_valid_parentheses(string s) {
        int len1 = lvp(s);
        cout << "len1 = " << len1 << endl;
        string s_rev; s_rev.resize(s.length());
        reverse_copy(s.begin(), s.end(), s_rev.begin());
        for (int i = 0; i < s_rev.length(); i++) {
            if (s_rev[i] == '(') s_rev[i] = ')';
            else if (s_rev[i] == ')') s_rev[i] = '(';
        }
        int len2 = lvp(s_rev);
        cout << "len2 = " << len2 << endl;
        return (len1<len2) ? len2 : len1;
    }

    void test_case1() {
        std::string str = "()()";
        int len = longest_valid_parentheses(str);
        printf("len=%d\n", len);
    }
};

}
