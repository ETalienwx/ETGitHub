//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
//����һ
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
	printf("һ�����Ժ�%dƿ\n", sum);
    system("pause");
    return 0;
}


//������
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int money = 20;
	int sum = 2 * money - 1;
	printf("һ�����Ժ�%dƿ\n", sum);
	system("pause");
	return 0;
}