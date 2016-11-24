#ifndef K_MEANS_H
#define K_MEANS_H

#include <CommonDataStructure.h>

struct Point {
    float x;
    float y;

    Point() {}
    Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}
    Point(const Point &anotherPoint) : x(anotherPoint.x), y(anotherPoint.y) {}

    float distance(const Point &anotherPoint) const {
        return std::sqrt((x - anotherPoint.x) * (x - anotherPoint.x) +
                         (y - anotherPoint.y) * (y - anotherPoint.y));
    }

    Point operator+(const Point &anotherPoint) {
        return Point(x+anotherPoint.x, y+anotherPoint.y);
    }

    Point operator*(const float scalor) {
        return Point(x * scalor, y * scalor);
    }
};

class KMeans{
public:
    KMeans() {}

    KMeans(const int numOfIterations) : mNumOfIterations(numOfIterations) {}

    KMeans(const std::vector<Point> &points, const unsigned int &kValue) : mPoints(points), mKvalue(kValue), mCenters(kValue, Point())
    {}

    void clear() {
        mPoints.clear();
        mCenters.clear();
    }

    void setPoints(const std::vector<Point> &points) {
        mPoints = points;
    }

    void setKVal(const unsigned int &K) {
        mKvalue = K;
        mCenters.clear();
        mCenters.resize(K);
    }

    void setNumOfIterations(const int numOfIterations) {
        mNumOfIterations = numOfIterations;
    }

    void compute() {
        getInitialPoints();
        shiftCenters();

        for (Point pt : mCenters) {
            std::cout << "x = " << pt.x << " y = " << pt.y << std::endl;
        }
    }

    void test_case1() {
        std::random_device rd;
        std::mt19937 engine(rd());
        std::normal_distribution<float> normMeanPosOne(10., 0.05);
        std::normal_distribution<float> normMeanNegOne(-10., 0.05);

        std::vector<Point> points;
        unsigned int numOfPointsPerCluster = 100;
        for (unsigned int i = 0; i < numOfPointsPerCluster; ++i) {
            points.push_back(Point(normMeanPosOne(engine), normMeanPosOne(engine)));
        }
        for (unsigned int i = 0; i < numOfPointsPerCluster; ++i) {
            points.push_back(Point(normMeanNegOne(engine), normMeanPosOne(engine)));
        }
        for (unsigned int i = 0; i < numOfPointsPerCluster; ++i) {
            points.push_back(Point(normMeanNegOne(engine), normMeanNegOne(engine)));
        }
        for (unsigned int i = 0; i < numOfPointsPerCluster; ++i) {
            points.push_back(Point(normMeanPosOne(engine), normMeanNegOne(engine)));
        }

        this->setPoints(points);
        this->setKVal(5);
        this->setNumOfIterations(1000);

        this->compute();
    }

private:

    std::vector<std::pair<float,unsigned int>> calcDistFromAllPointsTo(const Point &target) {
        std::vector<std::pair<float,unsigned int>> distsFromAllPointsToOnePoint(mPoints.size());
        for (size_t pIdx = 0; pIdx < mPoints.size(); ++pIdx) {
            distsFromAllPointsToOnePoint[pIdx] = std::make_pair(target.distance(mPoints[pIdx]), pIdx);
        }
        return distsFromAllPointsToOnePoint;
    }

    std::vector<std::pair<float,unsigned int>> calcDistFromAllPointsToNearestOf(const std::vector<Point> &targets) {
        std::vector<std::pair<float,unsigned int>> distsFromAllPointsToOnePoint(mPoints.size());
        for (size_t pIdx = 0; pIdx < mPoints.size(); ++pIdx) {
            distsFromAllPointsToOnePoint[pIdx].first = std::numeric_limits<float>::max();
            for (size_t tIdx = 0; tIdx < targets.size(); ++tIdx) {
                float curDist = targets[tIdx].distance(mPoints[pIdx]);
                if (curDist < distsFromAllPointsToOnePoint[pIdx].first) {
                    distsFromAllPointsToOnePoint[pIdx] = std::make_pair(curDist, pIdx);
                }
            }
        }
        return distsFromAllPointsToOnePoint;
    }

    void getInitialPoints() {
        std::random_device rd;
        std::mt19937 engine(rd());
        std::vector<unsigned int> indicesOfInitCenters;
        std::uniform_int_distribution<unsigned int> uniIntDistribution(0, mPoints.size()-1);
        unsigned int firstIndex = uniIntDistribution(engine); indicesOfInitCenters.push_back(firstIndex);

        std::uniform_real_distribution<float> uniFloatDistribution(0.0, 1.0);
        for (unsigned int iter = 1; iter < mKvalue; ++iter) {
            std::vector<std::pair<float,unsigned int>> distsFromAllPointsToNearestPoints = calcDistFromAllPointsToNearestOf(mCenters);
            //std::sort(distsFromAllPointsToNearestPoints.begin(), distsFromAllPointsToNearestPoints.end(),
            //          [](const std::pair<float,unsigned int> &p1, const std::pair<float,unsigned int> &p2) {
            //                return p1.first < p2.first;
            //            }
            //          );

            std::transform(distsFromAllPointsToNearestPoints.begin(), distsFromAllPointsToNearestPoints.end(), distsFromAllPointsToNearestPoints.begin(),
                           [](const std::pair<float,unsigned int> &ele){return std::make_pair(ele.first*ele.first, ele.second);});

            float sumOfSquiredDistances = std::accumulate(distsFromAllPointsToNearestPoints.begin(), distsFromAllPointsToNearestPoints.end(), 0.0,
                                                          [](const float &p1, const std::pair<float,unsigned int> &p2) {
                                                                return p1 + p2.first;
                                                            });

            std::transform(distsFromAllPointsToNearestPoints.begin(), distsFromAllPointsToNearestPoints.end(), distsFromAllPointsToNearestPoints.begin(),
                           [sumOfSquiredDistances](const std::pair<float,unsigned int> &ele){return std::make_pair(ele.first / sumOfSquiredDistances, ele.second);});


            float randFloatVal = uniFloatDistribution(engine);
            float accumProb = 0.0;
            for (size_t idx = 0; idx < distsFromAllPointsToNearestPoints.size(); ++idx) {
                accumProb += distsFromAllPointsToNearestPoints[idx].first;
                if (accumProb > randFloatVal) {
                    indicesOfInitCenters.push_back(distsFromAllPointsToNearestPoints[idx].second);
                    break;
                }
            }
        }

        mCenters.clear();
        mCenters.resize(mKvalue);
        for (size_t idx = 0; idx < indicesOfInitCenters.size(); ++idx) {
            mCenters[idx] = mPoints[indicesOfInitCenters[idx]];
        }

    }

    void shiftCenters() {

        int countIter = 0;
        while (countIter < mNumOfIterations) {

            std::vector<Point> updatedCenters(mKvalue, Point(0.0, 0.0));
            for (size_t cIdx = 0; cIdx < mKvalue; ++cIdx) {

                std::vector<std::pair<float,unsigned int>> distsFromAllPointsToOnePoint = calcDistFromAllPointsTo(mCenters[cIdx]);

                float sumOfAllDistances = std::accumulate(distsFromAllPointsToOnePoint.begin(), distsFromAllPointsToOnePoint.end(), 0.0,
                                                          [](const float &p1, const std::pair<float,unsigned int> &p2) {
                                                                return p1 + p2.first;
                                                            }
                                                          );
                if (sumOfAllDistances == 0) {
                    continue;
                }

                for (size_t pIdx = 0; pIdx < mPoints.size(); ++pIdx) {
                    updatedCenters[cIdx] = updatedCenters[cIdx] + mPoints[pIdx] * (distsFromAllPointsToOnePoint[pIdx].first / sumOfAllDistances);
                }
            }

            ++countIter;
        }
    }


private:
    std::vector<Point> mPoints;
    unsigned int mKvalue;
    std::vector<Point> mCenters;
    int mNumOfIterations;
};

#endif
