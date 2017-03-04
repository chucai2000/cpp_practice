#include "str_operations.h"

TEST(str_operations, execution)
{
    char *src = "hello_world!";
    char dst[100] = {0};
    char *dst_copy = str_operations::custom_str_copy(dst, src);

    for (size_t i = 0; i < strlen(dst_copy); ++i) {
        std::cout << dst_copy[i] << " ";
    }
    std::cout << std::endl;
}
