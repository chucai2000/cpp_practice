#include "common.h"
using namespace std;

namespace word_pattern_ii {

class Solution {
public:

    bool helper(string pattern, unsigned int p_idx, string str, unsigned int s_idx, unordered_map<char,string> & pattern_to_str, unordered_map<string,char> & str_to_pattern) {
        // base
        if (p_idx == pattern.size() && s_idx == str.size()) {
            return true;
        }
        else if (p_idx == pattern.size() || s_idx == str.size()) {
            return false;
        }

        char pch = pattern[p_idx];
        for (size_t i = s_idx+1; i <= str.length(); ++i) {
            string sub = str.substr(s_idx, i-s_idx);
            if (pattern_to_str.count(pch)!=0 && str_to_pattern.count(sub)!=0 && pattern_to_str[pch]==sub && str_to_pattern[sub]==pch) {
                return helper(pattern, p_idx+1, str, i, pattern_to_str, str_to_pattern);
            }
            else if (pattern_to_str.count(pch) == 0 && str_to_pattern.count(sub) == 0) {
                pattern_to_str[pch] = sub;
                str_to_pattern[sub] = pch;
                if (helper(pattern, p_idx+1, str, i, pattern_to_str, str_to_pattern)) {
                    return true;
                }
                pattern_to_str.erase(pch);
                str_to_pattern.erase(sub);

            }
        }

        return false;
    }

    bool word_pattern_match(string pattern, string str) {
        unordered_map<char,string> pattern_to_str;
        unordered_map<string,char> str_to_pattern;
        return helper(pattern, 0, str, 0, pattern_to_str, str_to_pattern);
    }

    void test_case1() {
        string pattern = "itwasthebestoftimes";
        string str = "ittwaastthhebesttoofttimesss";
        bool res = word_pattern_match(pattern, str);
        std::cout << res << std::endl;
    }
};

}
