#include "max_sum.h"

TEST(max_sum, execution)
{
    int A[] = {-3, 5, 6, -1, 2, -9, 0, -7};
    int start_pos = 0, end_pos = 0;
    int max_result = max_sum::max_sum(A, 8, &start_pos, &end_pos);
    EXPECT_EQ(max_result, 12);
}
