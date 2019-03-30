//Ä£ÄâÊµÏÖstrcat
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char * my_strcat(char* dest, char*src)
{
	assert(dest&&src);
	char *ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "hello ";
	char arr2[] = "world";
	printf("%s\n", my_strcat(arr1, arr2));
	system("pause");
	return 0;
}