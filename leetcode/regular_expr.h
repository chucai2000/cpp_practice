#include "common.h"
using namespace std;

namespace regular_expr {

class Solution {
public:

    bool is_match_helper(string s, unsigned int s_start, string p, unsigned int p_start) {
        if (p_start >= p.size() && s_start >= s.size()) return true;
        else if (p_start >= p.size()) return false;
        else if (s_start >= s.size()) {
            unsigned int star_index = p_start+1;
            while (star_index < p.size()) {
                if (p[star_index] != '*') return false;
                star_index += 2;
            }
            return star_index > p.size();
        }
        else {
             if (p_start+1 < p.size() && p[p_start+1] == '*') {
                 // .* or a*
                 while (p_start+3 < p.size() && p[p_start+3] == '*' && p[p_start+2] == p[p_start]) {
                     p_start += 2;
                 }
                 bool matched = is_match_helper(s, s_start, p, p_start+2);
                 matched |= (p[p_start]=='.' || p[p_start]==s[s_start]) && is_match_helper(s, s_start+1, p, p_start);
                 return matched;
             }
             else {
                 return (p[p_start]=='.' || p[p_start]==s[s_start]) && is_match_helper(s, s_start+1, p, p_start+1);
             }
        }

    }

    bool is_match_dfs(string s, string p) {
        return is_match_helper(s, 0, p, 0);
    }

    /////////////////////////////////////////////////
    vector<string> get_token_patterns(string p) {
        unsigned int i = 0;
        vector<string> token_patterns;
        while (i < p.size()) {
            if (i+1 < p.size() && p[i+1]=='*') {
                token_patterns.push_back(p.substr(i, 2));
                i+=2;
            }
            else {
                token_patterns.push_back(p.substr(i, 1));
                i++;
            }
        }
        return token_patterns;
    }

    bool is_match(string s, string p) {

        vector<string> tp = get_token_patterns(p);
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
        bool result = is_match("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b");
        std::cout << result << std::endl;
    }
};

}
