// µœ÷memcpy

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void *my_memcpy(void* dest,const void* src, size_t sz)
{
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	unsigned int i = 0;
	assert(pdest && psrc);
	for (i = 0; i < sz; i++)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
	}
	return dest;
}
int main()
{
	int arr1[10] = { 0 };
	int arr2[10] = { 1, 2, 3, 4, 5 };
	my_memcpy(arr1, arr2, 5 * sizeof(arr2[0]));
	system("pause");
	return 0;
}