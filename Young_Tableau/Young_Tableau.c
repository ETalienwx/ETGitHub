//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//1 2 3
//4 5 6
//7 8 9
#include <stdio.h>
#include <stdlib.h>
int find(int arr[3][3], int *px, int *py, int k)
{
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y]<k)
			x++;//若某一行的最右侧元素小于我们要查找的值，我们则去掉一行
		else if (arr[x][y]>k)
			y--;//若某一行的最右侧元素大于我们要查找的值，我们则去掉一列
		else
		{
			//返回型参数
			//这里找到的x和y就是我们的下标
			*px = x;//把x的值赋给*px，*px就是外面的x
			*py = y;//把y的值赋给*py，*py就是外面的y
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 7;
	int x = 3;
	int y = 3;
	int ret = find(arr, &x, &y, k);
	if (ret == 1)
	{
		printf("找到了:>%d %d\n",x,y);
	}
	else
	{
		printf("没有找到\n");
	}
	system("pause");
	return 0;
}