//д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.���۰���ң� 

//����1��
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 7;
//	int left = arr[0];
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left<=right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == k)
//		{
//			printf("�ҵ���,�±�Ϊ��%d\n",mid);
//			break;
//		}
//		else if (arr[mid] <= k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	if (left > right)
//	{
//		printf("û���ҵ�\n");
//	}
//	system("pause");
//	return 0;
//}

//��������(��Ϊ��������)

//#include <stdio.h>
//#include <string.h>
//int binary_search(int arr[], int k,int sz)
//{
//	int left = 0;
//	int right = sz;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == k)
//		{
//			return mid;
//		}
//		else if (arr[mid] <= k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 7;
//	int left = 0;
//	int sz = sizeof (arr) / sizeof (arr[0]) - 1;
//	int right = sz;
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("û���ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±�Ϊ��%d\n",mid);
//	}
//	system("pause");
//	return 0;
//}
