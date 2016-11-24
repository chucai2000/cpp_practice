#ifndef WORD_PATTERN_II_H
#define WORD_PATTERN_II_H

#include "CommonDataStructure.h"
using namespace std;

class Solution {
public:

    bool helper(string pattern, int pIdx, string str, unsigned int sIdx, unordered_map<char,string> & patternToStr, unordered_map<string,char> & strToPattern) {
        // base
        if (pIdx == pattern.size() && sIdx == str.size()) {
            return true;
        }
        else if (pIdx == pattern.size() || sIdx == str.size()) {
            return false;
        }

        char pch = pattern[pIdx];
        for (size_t i = sIdx+1; i <= str.length(); ++i) {
            string sub = str.substr(sIdx, i-sIdx);
            if (patternToStr.count(pch)!=0 && strToPattern.count(sub)!=0 && patternToStr[pch]==sub && strToPattern[sub]==pch) {
                return helper(pattern, pIdx+1, str, i, patternToStr, strToPattern);
            }
            else if (patternToStr.count(pch) == 0 && strToPattern.count(sub) == 0) {
                patternToStr[pch] = sub;
                strToPattern[sub] = pch;
                if (helper(pattern, pIdx+1, str, i, patternToStr, strToPattern)) {
                    return true;
                }
                patternToStr.erase(pch);
                strToPattern.erase(sub);

            }
        }

        return false;
    }

    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char,string> patternToStr;
        unordered_map<string,char> strToPattern;
        return helper(pattern, 0, str, 0, patternToStr, strToPattern);
    }

    void test_case1() {
        string pattern = "itwasthebestoftimes";
        string str = "ittwaastthhebesttoofttimesss";
        bool res = wordPatternMatch(pattern, str);
        int ep = 0;
    }
};

#endif
