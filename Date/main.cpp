#include "Date.h"

int main()
{
	Date d1;//Ĭ�Ϲ���
	d1.Print();
	Date d2(2019, 1, 1);//����
	d2.Print();
	Date d3(d2);//��������
	d3.Print();
	Date d4;
	d4.Print();
	d4 = d3;//��ֵ
	d4.Print();

	Date (2016, 2, 29).Print();//��������

	Date d5(2017, 10, 4);//���ڼ�100��
	Date d6 = d5 + 100;
	d6.Print();

	Date d7(2018,1,12);//���ڼ�100��
	Date d8 = d7 - 100;
	d8.Print();

	Date d9(1900, 11, 20);//+=
	d9 += 100;
	d9.Print();

	Date d10(1901, 2, 28);//-=
	d10 -= 100;
	d10.Print();

	Date d11(2019, 2, 27);//���ڼ�����
	Date d12(2019, 7, 15);
	int ret = d12 - d11;
	std::cout << ret << std::endl;

	//++
	Date d13(2019, 8, 8);
	(++d13).Print();//2019-8-9
	(d13++).Print();//2019-8-9
	d13.Print();//2019-8-10

	system("pause");
	return 0;
}