#include "word_ladder.h"

TEST(word_ladder, execution)
{
    unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    vector<vector<string>> res =
        word_ladder::find_ladders(std::string("hit"), std::string("cog"), dict);

    for (vector<string> const &group : res) {
        for (string const &word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}
