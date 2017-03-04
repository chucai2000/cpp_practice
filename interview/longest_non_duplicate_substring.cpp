#include "longest_non_duplicate_substring.h"

TEST(longest_non_duplicate_substring, execution)
{
    /* Driver program to test above function */
    char str[] = "geeksforkgeeks";
    std::cout << "The input string is " << str << std::endl;
    int len =  longest_non_duplicate_substring::longest_unique_substtr(str, 14);
    EXPECT_EQ(len, 7);
}
