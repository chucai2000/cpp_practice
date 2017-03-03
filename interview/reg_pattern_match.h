#include "common.h"
using namespace std;


namespace reg_pattern_match {

bool reg_match(string src, char pattern);

bool reg_match(string src, string pattern)
{
    if (src.size() == 0 && pattern.size() == 0)
        return true;

    if (pattern.size() == 1){

        // pattern[0] should be '.' or a character
        if (
            (pattern[0] == '.' && src.size() == 1)
            || (pattern[0] == src[0])
            ){

            return true;

        }
        else
            return false;
    }



    // when pattern.size() >= 2
    string src_head, pattern_head, src_tail, pattern_tail;
    bool result;

    if (pattern[1] != '*' && pattern[1] != '?'){
        src_head = src.substr(0,1);
        pattern_head = pattern.substr(0,1);
        src_tail = src.substr(1);
        pattern_tail = pattern.substr(1);
        result = reg_match(src_head, pattern_head);
        result = result & reg_match(src_tail, pattern_tail);
        return result;
    }

    else if (pattern[1] == '?') {
        src_head = src.substr(0, 1);
        pattern_head = pattern.substr(0, 2);
        src_tail = src.substr(1);
        pattern_tail = pattern.substr(2);
        if (!reg_match(src_head, pattern_head[0]))
            result = reg_match(src, pattern_tail);
        else
            result = reg_match(src_tail, pattern_tail);
        return result;
    }

    else if (pattern[1] == '*') {
        src_head = src.substr(0, 1);
        pattern_head = pattern.substr(0, 2);
        src_tail = src.substr(1);
        pattern_tail = pattern.substr(2);
        if (!reg_match(src_head, pattern_head[0])){
            result = reg_match(src, pattern_tail);
        }
        else {

            while (reg_match(src_tail.substr(0, 1), pattern_head[0])){

                if (src_tail.size() == 1){
                    src_tail = "";
                    break;
                }

                src_tail = src_tail.substr(1);

            }

            result = reg_match(src_tail, pattern_tail);

        }

        return result;
    }

    return false;
}

bool reg_match(string src, char pattern)
{
    string sz_pattern; sz_pattern.push_back(pattern);
    return reg_match(src, sz_pattern);
}

class Solution {
public:
    void test_case1()
    {
        string src, pattern;
        bool result;

        src = "abcde";
        pattern = "b?bb..e";
        result = reg_match(src, pattern);
        std::cout << result << std::endl;

        src = "abcde";
        pattern = "abs?c.*";
        result = reg_match(src, pattern);
        std::cout << result << std::endl;
    }
};

}
