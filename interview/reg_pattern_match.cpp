#include "reg_pattern_match.h"

TEST(reg_pattern_match, execution)
{
    string src, pattern;
    bool result;

    src = "abcde";
    pattern = "b?bb..e";
    result = reg_pattern_match::reg_match(src, pattern);
    std::cout << result << std::endl;

    src = "abcde";
    pattern = "abs?c.*";
    result = reg_pattern_match::reg_match(src, pattern);
    std::cout << result << std::endl;
}
