#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//整数转罗马数字
char* intToRoman(int num) {
	char* ret = (char*)malloc(sizeof(char) * (16));;
	int n = 0;
	int flag = 0;
	if (num >= 1000)
	{
		n = num / 1000;
		num %= 1000;
		while (n--)
		{
			ret[flag] = 'M';
			flag++;			}
	}
	if (num >= 900)
	{
		ret[flag] = 'C';
		ret[flag + 1] = 'M';
		num %= 900;
		flag += 2;
	}
	if (num >= 500)
	{
		ret[flag] = 'D';
		num %= 500;
		flag++;
	}
	if (num >= 400)
	{
		ret[flag] = 'C';
		ret[flag + 1] = 'D';
		num %= 400;
		flag += 2;
	}
	if (num >= 100)
	{
		n = num / 100;
		num %= 100;
		while (n--)
		{
			ret[flag] = 'C';
			flag++;
		}
	}
	if (num >= 90)
	{
		ret[flag] = 'X';
		ret[flag + 1] = 'C';
		num %= 90;
		flag += 2;
	}
	if (num >= 50)
	{
		ret[flag] = 'L';
		num %= 50;
		flag++;
	}
	if (num >= 40)
	{
		ret[flag] = 'X';
		ret[flag + 1] = 'L';
		num %= 40;
		flag += 2;
	}
	if (num >= 10)
	{
		n = num / 10;
		num %= 10;
		while (n--)
		{
			ret[flag] = 'X';
			flag++;
		}
	}
	if (num >= 9)
	{
		ret[flag] = 'I';
		ret[flag + 1] = 'X';
		num %= 9;
		flag += 2;
	}
	if (num >= 5)
	{
		ret[flag] = 'V';
		num %= 5;
		flag++;
	}
	if (num >= 4)
	{
		ret[flag] = 'I';
		ret[flag + 1] = 'V';
		num %= 4;
		flag += 2;
	}
	if (num >= 0)
	{
		n = num / 1;
		num %= 1;
		while (n--)
		{
			ret[flag] = 'I';
			flag++;
		}
	}
	ret[flag] = '\0';
	return ret;
}

//整数转罗马数字的main函数
//int main()
//{
//	int test = 999;
//	char* ret = intToRoman(test);
//	printf("%s", ret);
//	return 0;
//}