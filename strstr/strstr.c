//实现strstr

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* my_strstr(const char *str, const char*substr)
{
	const char* s1 = str;
	const char* s2 = substr;
	const char* cur = str;
	while (*cur)
	{
		s1 = cur;
		s2 = substr;
		while (*s1 && *s2 && (*s1==*s2))
		{
			s1++;
			s2++;
		}
		if (*s1 == '\0')
			return NULL;
		if (*s2 == '\0')
			return (char *)cur;
		cur++;
	}
	return NULL;
}
int main()
{
	char *p = "abcdefabcdef";
	char *q = "bcd";
	char *ret = my_strstr(p, q);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		printf("找不到\n");
	system("pause");
	return 0;
}