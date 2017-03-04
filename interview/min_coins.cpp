#include "min_coins.h"

TEST(min_coins, execution)
{
    int exp_value = 3;
    int coin[] = {1, 5, 10, 25};
    int minnum = min_coins::min_coins(exp_value, coin);
    EXPECT_EQ(minnum, 3);
}
