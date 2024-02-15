#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//有效的括号
bool isValid(char* s) {
	int number = strlen(s);
	if (number == 0)
	{
		return false;
	}
	char* p= NULL;
	int n = 0;
	int size = 0;
	bool big = false;
	bool mid = false;
	while (n < number)
	{
		if (s[n] == '{')
		{
			size++;
			p = (char*)realloc(p, size * sizeof(char));
			p[size - 1] = '{';
			big = true;
		}
		if (s[n] == '[')
		{
			size++;
			p = (char*)realloc(p, size * sizeof(char));
			p[size-1] = '[';
			mid = true;
		}
		if (s[n] == '(')
		{
			size++;
			p = (char*)realloc(p, size * sizeof(char));
			p[size-1] = '(';
		}
		if (s[n] == ')')
		{
			if (size == 0 || p[size - 1] != '(')
			{
				return false;
			}
			else
			{
				size--;
			}
		}
		if (s[n] == ']')
		{
			if (size == 0 || p[size - 1] != '[')
			{
				return false;
			}
			else
			{
				mid = false;
				size--;
			}
		}
		if (s[n] == '}')
		{
			if (size == 0 || p[size - 1] != '{')
			{
				return false;
			}
			else
			{
				big = false;
				size--;
			}
		}
		n++;
	}
	if (!mid && !big && !size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//有效的括号的main函数
//int main()
//{
//	char arr[] = "()";
//	bool a = isValid(arr);
//	printf("%d", a);
//	return 0;
//}