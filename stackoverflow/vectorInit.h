#ifndef _VECTOR_INIT_H_
#define _VECTOR_INIT_H_

#include "CommonDataStructure.h"

class Solution {

float viewerMatrix[4][4] =
{
    {0.99962944, -0.023989394, -0.012864082, -0.032067116},
    {0.02354476, 0.9991557, -0.033667795, -0.0060634422},
    {0.013660891, 0.033352438, 0.99935031, 0.047027141},
    {   0, 0, 0, 1}
};

public:

void testCase1() {
    int *p = NULL; std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(viewerMatrix) << std::endl;
    std::cout << sizeof(viewerMatrix[0]) << std::endl;
    std::vector<std::vector<float> > floatVector;
    for (size_t i = 0; i < 4; i++) {
        std::vector<float> v(viewerMatrix[i], viewerMatrix[i]+sizeof(viewerMatrix[i])/sizeof(viewerMatrix[i][0]));
        floatVector.push_back(v);
        std::cout << v[0] << " " << v[1] << std::endl;
    }
}

};

#endif

