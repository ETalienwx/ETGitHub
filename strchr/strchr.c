//ÊµÏÖstrchr

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char  *my_strchr(const char *arr, char ch)
{
	assert(arr);
	while (*arr != '\0')
	{
		if (*arr == ch)
		{
			return (char*)arr;
		}
		arr++;
	}
	return NULL;
}
int main()
{
	char arr[] = "abccd";
	printf("%s\n", my_strchr(arr, 'c'));
	system("pause");
	return 0;
}