//模拟实现printf函数，可完成下面的功能
//能完成下面函数的调用。 
//print("s ccc d.\n","hello",'b','i','t'，100); 
//函数原型： 
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