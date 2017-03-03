#include "common.h"

namespace str_operations {

class Solution {
public:

    char *custom_str_copy(char *dst, const char *src)
    {
        const char *preserved = src;
        char *dst_copy = dst;

        while (*dst_copy++ = *src++)
            ;

        *dst_copy = '\0';

        return dst;
    }

    int test_case1()
    {
        char *src = "hello_world!";
        char dst[100];
        char *dst_copy = custom_str_copy(dst, src);

        return 0;
    }

};

}
