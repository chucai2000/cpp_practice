#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

#include "common.h"
using namespace std;

class Solution {
public:
    std::pair<string, int> findFirstToken(string str) {
        unsigned int newLineCharIndex = str.find("\n");
        unsigned int tokenIndex = newLineCharIndex == string::npos ? str.length() : newLineCharIndex;
        unsigned int lastTabIndex = newLineCharIndex;
        if (newLineCharIndex != string::npos) {
            while (lastTabIndex + 1 < str.length() && str[lastTabIndex + 1] == '\t') {
                ++lastTabIndex;
            }
        }
        return std::make_pair(str.substr(0, tokenIndex), int(lastTabIndex - newLineCharIndex));
    }

    bool isDir(string token) {
        return token.find(".") == string::npos;
    }

    int mergedPathLen(vector<string> &stk, unsigned int lastNumOfTabs, string &filename) {
        int result = 0;
        if (lastNumOfTabs > stk.size()) {
            throw std::runtime_error("The most recent number of tabs should not exceed stack size.");
        }
        for (size_t idx = 0; idx < lastNumOfTabs; ++idx) {
            result += stk[idx].length() + 1;
        }
        result += filename.length();
        return result;
    }

    int lengthLongestPath(string input) {

        std::vector<std::string> stk;
        std::string curStr = input;
        int maxLen = 0;

        unsigned int lastNumOfTabs = 0;
        while (!curStr.empty()) {
            std::pair<string, int> tokenQuery = findFirstToken(curStr);

            if (isDir(tokenQuery.first)) {
                // directory
                if (lastNumOfTabs == stk.size()) {
                    stk.push_back(tokenQuery.first);
                }
                else if (lastNumOfTabs < stk.size()) {
                    int count = stk.size() - lastNumOfTabs;
                    while (count-- > 0) {
                        stk.pop_back();
                    }
                    stk.push_back(tokenQuery.first);
                }
                else {
                    throw std::runtime_error("The most recent number of tabs should not exceed stack size.");
                }

                lastNumOfTabs = tokenQuery.second;
            }
            else {
                int pathLen = mergedPathLen(stk, lastNumOfTabs, tokenQuery.first);
                if (pathLen > maxLen) {
                    maxLen = pathLen;
                }
                lastNumOfTabs = tokenQuery.second;
            }

            if (tokenQuery.first.length() + 1 + tokenQuery.second >= curStr.size())
                curStr = "";
            else
                curStr = curStr.substr(tokenQuery.first.length() + 1 + tokenQuery.second);

            for (size_t idx = 0; idx < stk.size(); ++idx) {
                printf("%s, ", stk[idx].c_str());
            }
            printf("\n");
        }

        return maxLen;
    }

    void test_case1() {
        string input("a\n\tb1\n\t\tf1.txt\n\taaaaa\n\t\tf2.txt");
        int len = lengthLongestPath(input);
        printf("%d\n", len);
    }
};

#endif

