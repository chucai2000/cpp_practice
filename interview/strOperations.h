#include <stdio.h>

char *customStrCopy(char *dst, const char *src)
{
	const char *preserved = src;
	char *dstCopy = dst;

	while (*dstCopy++ = *src++)
		;

	*dstCopy = '\0';

	return dst;
}

int test()
{
	char *src = "HelloWorld!";
	char dst[100];
	char *dstCopy = customStrCopy(dst, src);

	return 0;
}