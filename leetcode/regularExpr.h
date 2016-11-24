#ifndef _REG_EXPR_H_
#define _REG_EXPR_H_

#include "CommonDataStructure.h"
using namespace std;

class Solution {
public:

    bool isMatchHelper(string s, unsigned int sStart, string p, unsigned int pStart) {
        if (pStart >= p.size() && sStart >= s.size()) return true;
        else if (pStart >= p.size()) return false;
        else if (sStart >= s.size()) {
            unsigned int starIndex = pStart+1;
            while (starIndex < p.size()) {
                if (p[starIndex] != '*') return false;
                starIndex += 2;
            }
            return starIndex > p.size();
        }
        else {
             if (pStart+1 < p.size() && p[pStart+1] == '*') {
                 // .* or a*
                 while (pStart+3 < p.size() && p[pStart+3] == '*' && p[pStart+2] == p[pStart]) {
                     pStart += 2;
                 }
                 bool matched = isMatchHelper(s, sStart, p, pStart+2);
                 matched |= (p[pStart]=='.' || p[pStart]==s[sStart]) && isMatchHelper(s, sStart+1, p, pStart);
                 return matched;
             }
             else {
                 return (p[pStart]=='.' || p[pStart]==s[sStart]) && isMatchHelper(s, sStart+1, p, pStart+1);
             }
        }

    }

    bool isMatch_dfs(string s, string p) {
        return isMatchHelper(s, 0, p, 0);
    }

    /////////////////////////////////////////////////
    vector<string> getTokenPatterns(string p) {
        int i = 0;
        vector<string> tokenPatterns;
        while (i < p.size()) {
            if (i+1 < p.size() && p[i+1]=='*') {
                tokenPatterns.push_back(p.substr(i, 2));
                i+=2;
            }
            else {
                tokenPatterns.push_back(p.substr(i, 1));
                i++;
            }
        }
        return tokenPatterns;
    }

    bool isMatch(string s, string p) {

        vector<string> tp = getTokenPatterns(p);
        int N = s.size();
        int M = tp.size();

        vector<vector<int>> match(M+1);
        for (int i = 0; i <= M; ++i) {
            match[i].resize(N+1, 0);
        }
        match[0][0] = 1;

        for (int i = 1; i <= M; i++) {
            if (tp[i-1].size()==2) {
                match[i][0] = 1;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (tp[i-1].size()==2) {
                    match[i][j] = match[i-1][j] || ((tp[i-1][0]=='.' || tp[i-1][0]==s[j-1]) && match[i][j-1]);
                }
                else {
                    match[i][j] = match[i-1][j-1] && (tp[i-1][0]=='.' || tp[i-1][0]==s[j-1]);
                }
            }
        }
        return match[M][N];
    }

    void test_case1() {
        bool result = false;
        //result = isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b");
        int ep = 0;
    }
};

#endif
