#include "common.h"

namespace lonely_index {

class Solution {
public:
    int findLonelyPixel(std::vector<std::vector<char>>& picture) {
        unsigned int rows = picture.size();
        if (rows == 0) return 0;
        unsigned int cols = picture[0].size();

        std::vector<unsigned int> r_blacks(rows, 0);
        std::vector<unsigned int> c_blacks(cols, 0);
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                if (picture[i][j] == 'B') {
                    r_blacks[i]++;
                    c_blacks[j]++;
                }
            }
        }

        int lonely = 0;
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                if (picture[i][j] == 'B') {
                    if (r_blacks[i] == 1 && c_blacks[j] == 1) {
                        lonely++;
                    }
                }
            }
        }
        return lonely;
    }

    void test_case1() {
        std::vector<std::vector<char>> picture1 = {
            {'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
        int res1 = findLonelyPixel(picture1);
        std::cout << "res1 = " << res1 << std::endl;

        std::vector<std::vector<char>> picture2 = {
            {'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}};
        int res2 = findLonelyPixel(picture2);
        std::cout << "res2 = " << res2 << std::endl;
    }
};

}
