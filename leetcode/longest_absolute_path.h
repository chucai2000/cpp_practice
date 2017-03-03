#include "common.h"
using namespace std;

namespace longest_absolute_path {

class Solution {
public:
    std::pair<string, int> find_first_token(string str) {
        unsigned int new_line_char_index = str.find("\n");
        unsigned int token_index = new_line_char_index == string::npos ? str.length() : new_line_char_index;
        unsigned int last_tab_index = new_line_char_index;
        if (new_line_char_index != string::npos) {
            while (last_tab_index + 1 < str.length() && str[last_tab_index + 1] == '\t') {
                ++last_tab_index;
            }
        }
        return std::make_pair(str.substr(0, token_index), int(last_tab_index - new_line_char_index));
    }

    bool is_dir(string token) {
        return token.find(".") == string::npos;
    }

    int merged_path_len(vector<string> &stk, unsigned int last_num_of_tabs, string &filename) {
        int result = 0;
        if (last_num_of_tabs > stk.size()) {
            throw std::runtime_error("The most recent number of tabs should not exceed stack size.");
        }
        for (size_t idx = 0; idx < last_num_of_tabs; ++idx) {
            result += stk[idx].length() + 1;
        }
        result += filename.length();
        return result;
    }

    int length_longest_path(string input) {

        std::vector<std::string> stk;
        std::string cur_str = input;
        int max_len = 0;

        unsigned int last_num_of_tabs = 0;
        while (!cur_str.empty()) {
            std::pair<string, int> token_query = find_first_token(cur_str);

            if (is_dir(token_query.first)) {
                // directory
                if (last_num_of_tabs == stk.size()) {
                    stk.push_back(token_query.first);
                }
                else if (last_num_of_tabs < stk.size()) {
                    int count = stk.size() - last_num_of_tabs;
                    while (count-- > 0) {
                        stk.pop_back();
                    }
                    stk.push_back(token_query.first);
                }
                else {
                    throw std::runtime_error("The most recent number of tabs should not exceed stack size.");
                }

                last_num_of_tabs = token_query.second;
            }
            else {
                int path_len = merged_path_len(stk, last_num_of_tabs, token_query.first);
                if (path_len > max_len) {
                    max_len = path_len;
                }
                last_num_of_tabs = token_query.second;
            }

            if (token_query.first.length() + 1 + token_query.second >= cur_str.size())
                cur_str = "";
            else
                cur_str = cur_str.substr(token_query.first.length() + 1 + token_query.second);

            for (size_t idx = 0; idx < stk.size(); ++idx) {
                printf("%s, ", stk[idx].c_str());
            }
            printf("\n");
        }

        return max_len;
    }

    void test_case1() {
        string input("a\n\tb1\n\t\tf1.txt\n\taaaaa\n\t\tf2.txt");
        int len = length_longest_path(input);
        printf("%d\n", len);
    }
};

}


