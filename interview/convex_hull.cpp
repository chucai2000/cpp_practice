#include "convex_hull.h"

TEST(convex_hull, execution)
{
    convex_hull::Point points[12];
    points[0].x = 0; points[0].y = 0;
    points[1].x = 0; points[1].y = 6;
    points[2].x = 1; points[2].y = 3;
    points[3].x = 2; points[3].y = 0;
    points[4].x = 2; points[4].y = 6;
    points[5].x = 3; points[5].y = 3;
    points[6].x = 4; points[6].y = 0;
    points[7].x = 4; points[7].y = 6;
    points[8].x = 5; points[8].y = 3;
    points[9].x = 6; points[9].y = 0;
    points[10].x = 6; points[10].y = 6;
    points[11].x = 7; points[11].y = 3;

    convex_hull::Point convex_hull_points[12];
    int num = convex_hull::chain_hull_2d(points, 12, convex_hull_points);
    EXPECT_EQ(num-1, 5);

    EXPECT_EQ(convex_hull_points[0], convex_hull::Point(0, 0));
}
