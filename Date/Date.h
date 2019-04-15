#pragma once
#include <iostream>
class Date
{
public:
	void Print()const;
	int Date::GetMonthDay(int year, int month)const;
	//���캯��
	Date(int year = 1900, int month = 1, int day = 1);
	//��������
	~Date();
	//��������Date d2(d1);
	Date(const Date& d);
	//��ֵ���������
	Date& operator=(const Date& d);
	//�Ƚ�����
	bool operator==(const Date&d)const;
	bool operator!=(const Date&d)const;
	bool operator>(const Date&d)const;
	bool operator<(const Date&d)const;
	bool operator>=(const Date&d)const;
	bool operator<=(const Date&d)const;
	//�������ڵļӼ�
	Date operator+(int day)const;//���ڼ�������ԭ���ڲ��䣬���Ҫ������ʱ����Ҫ��ֵ����
	Date& operator+=(int day);//���ڼ��������������ڸı䣬ֱ�Ӵ�����
	Date operator-(int day)const;//���ڼ�������ԭ���ڲ���
	Date& operator-=(int day);//���ڼ�ȥ�����������ڸı�
	int operator-(Date& d)const;//���ڼ����ڣ�����ֵ������int
	//ǰ��++(d.operator++(&d))
	Date& operator++();
	//����++(d.operator++(&d,0))
	Date operator++(int);
	//ǰ��--(d.operator--(&d))
	Date& operator--();
	//����--(d.operator--(&d,0))
	Date operator--(int);
private:
	int _year;
	int _month;
	int _day;
};