//实现memmove
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void* my_memmove(void* dest, const void* src, size_t sz)
{
	assert(dest && src);
	char* ret = (char*)dest;
	if (dest < src)
	{
		//前--后
		while (sz--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//后--前
		while (sz--)
		{
			*((char*)dest + sz) = *((char*)src + sz);
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	my_memmove(arr+2, arr, 4 * sizeof(arr[0]));
	system("pause");
	return 0;
}

