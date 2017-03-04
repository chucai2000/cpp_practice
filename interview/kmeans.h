#include "common.h"

namespace kmeans {

struct Point {

    float x;
    float y;

    Point() {}
    Point(const float x_val, const float y_val) : x(x_val), y(y_val) {}
    Point(const Point &another_point) : x(another_point.x), y(another_point.y) {}

    float distance(const Point &another_point) const {
        return std::sqrt((x - another_point.x) * (x - another_point.x) +
                         (y - another_point.y) * (y - another_point.y));
    }

    Point operator+(const Point &another_point) {
        return Point(x+another_point.x, y+another_point.y);
    }

    Point operator*(const float scalor) {
        return Point(x * scalor, y * scalor);
    }
};

class KMeans{
public:

    KMeans() {}

    KMeans(const int num_of_iterations) : m_num_of_iterations(num_of_iterations) {}

    KMeans(const std::vector<Point> &points, const unsigned int &k_value) : m_points(points), m_kvalue(k_value), m_centers(k_value, Point())
    {}

    void clear() {
        m_points.clear();
        m_centers.clear();
    }

    void set_points(const std::vector<Point> &points) {
        m_points = points;
    }

    void set_kval(const unsigned int &K) {
        m_kvalue = K;
        m_centers.clear();
        m_centers.resize(K);
    }

    void set_num_of_iterations(const int num_of_iterations) {
        m_num_of_iterations = num_of_iterations;
    }

    void compute() {
        get_initial_points();
        shift_centers();

        std::cout << "kmeans centers are: " << std::endl;
        for (Point pt : m_centers) {
            std::cout << "x = " << pt.x << " y = " << pt.y << std::endl;
        }
    }

private:

    std::vector<std::pair<float,unsigned int>> calc_dist_from_all_points_to(const Point &target) {
        std::vector<std::pair<float,unsigned int>> dists_from_all_points_to_one_point(m_points.size());
        for (size_t p_idx = 0; p_idx < m_points.size(); ++p_idx) {
            dists_from_all_points_to_one_point[p_idx] = std::make_pair(target.distance(m_points[p_idx]), p_idx);
        }
        return dists_from_all_points_to_one_point;
    }

    std::vector<std::pair<float,unsigned int>> calc_dist_from_all_points_toNearestOf(const std::vector<Point> &targets) {
        std::vector<std::pair<float,unsigned int>> dists_from_all_points_to_one_point(m_points.size());
        for (size_t p_idx = 0; p_idx < m_points.size(); ++p_idx) {
            dists_from_all_points_to_one_point[p_idx].first = std::numeric_limits<float>::max();
            for (size_t t_idx = 0; t_idx < targets.size(); ++t_idx) {
                float cur_dist = targets[t_idx].distance(m_points[p_idx]);
                if (cur_dist < dists_from_all_points_to_one_point[p_idx].first) {
                    dists_from_all_points_to_one_point[p_idx] = std::make_pair(cur_dist, p_idx);
                }
            }
        }
        return dists_from_all_points_to_one_point;
    }

    void get_initial_points() {
        std::random_device rd;
        std::mt19937 engine(rd());
        std::vector<unsigned int> indices_of_init_centers;
        std::uniform_int_distribution<unsigned int> uni_int_distribution(0, m_points.size()-1);
        unsigned int first_index = uni_int_distribution(engine); indices_of_init_centers.push_back(first_index);

        std::uniform_real_distribution<float> uni_float_distribution(0.0, 1.0);
        for (unsigned int iter = 1; iter < m_kvalue; ++iter) {
            std::vector<std::pair<float,unsigned int>> dists_from_all_points_to_nearest_points = calc_dist_from_all_points_toNearestOf(m_centers);
            std::sort(dists_from_all_points_to_nearest_points.begin(), dists_from_all_points_to_nearest_points.end(),
                      [](const std::pair<float,unsigned int> &p1, const std::pair<float,unsigned int> &p2) {
                            return p1.first < p2.first;
                        }
                      );

            std::transform(dists_from_all_points_to_nearest_points.begin(), dists_from_all_points_to_nearest_points.end(), dists_from_all_points_to_nearest_points.begin(),
                           [](const std::pair<float,unsigned int> &ele){return std::make_pair(ele.first*ele.first, ele.second);});

            float sum_of_squired_distances = std::accumulate(dists_from_all_points_to_nearest_points.begin(), dists_from_all_points_to_nearest_points.end(), 0.0,
                                                          [](const float &p1, const std::pair<float,unsigned int> &p2) {
                                                                return p1 + p2.first;
                                                            });

            std::transform(dists_from_all_points_to_nearest_points.begin(), dists_from_all_points_to_nearest_points.end(), dists_from_all_points_to_nearest_points.begin(),
                           [sum_of_squired_distances](const std::pair<float,unsigned int> &ele){return std::make_pair(ele.first / sum_of_squired_distances, ele.second);});


            float rand_float_val = uni_float_distribution(engine);
            float accum_prob = 0.0;
            for (size_t idx = 0; idx < dists_from_all_points_to_nearest_points.size(); ++idx) {
                accum_prob += dists_from_all_points_to_nearest_points[idx].first;
                if (accum_prob > rand_float_val) {
                    indices_of_init_centers.push_back(dists_from_all_points_to_nearest_points[idx].second);
                    break;
                }
            }
        }

        m_centers.clear();
        m_centers.resize(m_kvalue);
        for (size_t idx = 0; idx < indices_of_init_centers.size(); ++idx) {
            m_centers[idx] = m_points[indices_of_init_centers[idx]];
        }

    }

    void shift_centers() {

        int count_iter = 0;
        while (count_iter < m_num_of_iterations) {

            std::vector<Point> updated_centers(m_kvalue, Point(0.0, 0.0));
            for (size_t c_idx = 0; c_idx < m_kvalue; ++c_idx) {

                std::vector<std::pair<float,unsigned int>> dists_from_all_points_to_one_point = calc_dist_from_all_points_to(m_centers[c_idx]);

                float sum_of_all_distances = std::accumulate(dists_from_all_points_to_one_point.begin(), dists_from_all_points_to_one_point.end(), 0.0,
                                                          [](const float &p1, const std::pair<float,unsigned int> &p2) {
                                                                return p1 + p2.first;
                                                            }
                                                          );
                if (sum_of_all_distances == 0) {
                    continue;
                }

                for (size_t p_idx = 0; p_idx < m_points.size(); ++p_idx) {
                    updated_centers[c_idx] = updated_centers[c_idx] + m_points[p_idx] * (dists_from_all_points_to_one_point[p_idx].first / sum_of_all_distances);
                }
            }

            ++count_iter;
        }
    }


private:
    std::vector<Point> m_points;
    unsigned int m_kvalue;
    std::vector<Point> m_centers;
    int m_num_of_iterations;
};


}
