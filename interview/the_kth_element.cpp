#include "the_kth_element.h"

TEST(the_kth_element, execution)
{
    int arr[11] = {16,12,24,8,32,44,40,4,20,28,0};
    int ret = the_kth_element::rank(arr, 0, 10, 2);
    EXPECT_EQ(ret, 8);
}
