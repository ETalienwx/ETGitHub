//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
//方法一
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int money = 20;
	int sum = money;
	int empty = money;
	while (empty > 1)
	{
		sum += (empty / 2);
		empty -= (empty / 2);
	}
	printf("一共可以喝%d瓶\n", sum);
    system("pause");
    return 0;
}


//方法二
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int money = 20;
	int sum = 2 * money - 1;
	printf("一共可以喝%d瓶\n", sum);
	system("pause");
	return 0;
}