#include "largest_rectangle_histogram.h"

TEST(largest_rectangle_histogram,execution)
{
    vector<unsigned int> height;
    height.push_back(2);
    height.push_back(4);
    height.push_back(5);
    height.push_back(6);
    height.push_back(7);
    height.push_back(3);

    unsigned int result = largest_rectangle_histogram::largest_rectangle_area(height);
    EXPECT_EQ(result, (unsigned int)(16));
}
