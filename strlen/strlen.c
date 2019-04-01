//采用指针模拟实现strlen
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int * my_strlen(const char*str)
{
	assert(str);
	const char*start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}
int main()
{
	char *p = "abcdef";
	printf("%d\n", my_strlen(p));
	system("pause");
	return 0;
}
