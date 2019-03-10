//在屏幕上打印杨辉三角。

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[20][20] = {0};
	int i = 0;
	int j = 0;
	for (i = 1; i < 20; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (j == 1)
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j>1)
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
	for (i = 1; i < 20; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}