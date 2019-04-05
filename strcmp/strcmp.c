// µœ÷strcmp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int my_strcmp(const char* p1, const char* p2)
{
	assert(p1 && p2);
	while (*p1 == *p2)
	{
		if (p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return *p1 - *p2;
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "azaaaaaaa";
	int ret = my_strcmp(p1, p2);
	printf("%d\n", ret);
	system("pause");
	return 0;
}