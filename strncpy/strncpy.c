//Ä£ÄâÊµÏÖstrncpy
#include <stdio.h>
#include <assert.h>
char *my_strncpy(char *dest, const char* src, int sz) 
{
	assert(dest&&src);
	int i = 0;
	char *ret = dest;
	while (i < sz)
	{
		*dest++ = *src++;
		i++;
	}
	return ret;
}

int main()
{
	char arr[40] = { 0 };
	my_strncpy(arr, "hello world", 4);
	printf("%s\n", arr);
	system("pause");
	return 0;
}