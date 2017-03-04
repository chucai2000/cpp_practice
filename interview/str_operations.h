#include "common.h"

namespace str_operations {

char *custom_str_copy(char *dst, const char *src)
{
    const char *preserved = src;
    char *dst_copy = dst;

    while (*dst_copy++ = *src++)
        ;

    *dst_copy = '\0';

    return dst;
}


}
