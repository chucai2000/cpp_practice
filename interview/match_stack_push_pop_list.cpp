#include "match_stack_push_pop_list.h"

TEST(match_stack_push_pop_list, execution)
{
    int s1[] = { 1, 2, 3, 4, 5, 6, 7 };
    int s2[] = { 4, 3, 6, 5, 7, 2, 1 };
    vector<int> src(s1, s1+sizeof(s1)/sizeof(int));
    vector<int> dst(s2, s2+sizeof(s2)/sizeof(int));
    bool ret = match_stack_push_pop_list::confirm_stack(src, dst);
    EXPECT_TRUE(ret);
}
