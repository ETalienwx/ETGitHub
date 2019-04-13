//strncat
#include <stdio.h>
#include <assert.h>
char * my_strncat(char *dest, const char *src,int sz)
{
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (sz && *src)
	{
		*dest++ = *src++;
		sz--;
	}
	return ret;
}
int main()
{
	char arr[20] = "hello";
	my_strncat(arr, " world", 6);
	printf("%s\n", arr);
	system("pause");
	return 0;
}