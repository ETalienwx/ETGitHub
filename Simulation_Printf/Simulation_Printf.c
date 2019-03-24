//ģ��ʵ��printf���������������Ĺ���
//��������溯���ĵ��á� 
//print("s ccc d.\n","hello",'b','i','t'��100); 
//����ԭ�ͣ� 
//print(char *format, ...) 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show(int ret)
{
	if (ret > 9)
	{
		show(ret / 10);
	}
	putchar(ret % 10+'0');
}
void print(char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		switch (*format)
		{
		case 's':
		{
				char* ret=va_arg(arg, char *);
				while (*ret)
				{
					putchar(*ret);
					ret++;
				}
		}
			break;
		case 'c':
		{
					putchar(va_arg(arg, char));
		}
			break;
		case 'd':
		{
					
					int ret=va_arg(arg,int);
					show(ret);
		}
			break;
		default:
			putchar(*format);
			break;	  
		}
		format++;
	}
}
int main()
{
	print("s ccc d\n", "hello", 'b', 'i', 't',100);
	system("pause");
	return 0;
}