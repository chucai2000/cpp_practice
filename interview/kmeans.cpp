#include "kmeans.h"

TEST(kmeans, execution)
{
    kmeans::KMeans obj;
    std::random_device rd;
    std::mt19937 engine(rd());
    std::normal_distribution<float> norm_mean_pos_one(10., 0.05);
    std::normal_distribution<float> norm_mean_neg_one(-10., 0.05);

    std::vector<kmeans::Point> points;
    unsigned int num_of_points_per_cluster = 100;
    for (unsigned int i = 0; i < num_of_points_per_cluster; ++i) {
        points.push_back(kmeans::Point(norm_mean_pos_one(engine), norm_mean_pos_one(engine)));
    }
    for (unsigned int i = 0; i < num_of_points_per_cluster; ++i) {
        points.push_back(kmeans::Point(norm_mean_neg_one(engine), norm_mean_pos_one(engine)));
    }
    for (unsigned int i = 0; i < num_of_points_per_cluster; ++i) {
        points.push_back(kmeans::Point(norm_mean_neg_one(engine), norm_mean_neg_one(engine)));
    }
    for (unsigned int i = 0; i < num_of_points_per_cluster; ++i) {
        points.push_back(kmeans::Point(norm_mean_pos_one(engine), norm_mean_neg_one(engine)));
    }

    obj.set_points(points);
    obj.set_kval(5);
    obj.set_num_of_iterations(1000);
    obj.compute();
}
