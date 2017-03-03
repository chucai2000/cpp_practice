#include "vector_init.h"

TEST(vector_init, execution)
{
    int *p = NULL; std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(vector_init::viewer_matrix) << std::endl;
    std::cout << sizeof(vector_init::viewer_matrix[0]) << std::endl;
    std::vector<std::vector<float> > float_vector;
    for (size_t i = 0; i < 4; i++) {
        std::vector<float> v(vector_init::viewer_matrix[i],
                             vector_init::viewer_matrix[i]+
                             sizeof(vector_init::viewer_matrix[i])/sizeof(vector_init::viewer_matrix[i][0]));
        float_vector.push_back(v);
        std::cout << v[0] << " " << v[1] << std::endl;
    }
}
