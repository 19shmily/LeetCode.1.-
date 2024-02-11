#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//罗马数字转整数
int romanToInt(char* s) {
	int number = strlen(s) - 1;
	int ret = 0;
	while (number >= 0)
	{
		if (s[number] == 'I')
		{
			ret += 1;
			number--;
			continue;

		}
		if (s[number] == 'V')
		{
			ret += 5;
			number--;
			if (number < 0) { break; }
			if (s[number] == 'I')
			{
				ret -= 1;
				number--;
			}
			continue;
		}
		if (s[number] == 'X')
		{
			ret += 10;
			number--;
			if (number < 0) { break; }
			if (s[number] == 'I')
			{
				ret -= 1;
				number--;
			}
			continue;
		}
		if (s[number] == 'L')
		{
			ret += 50;
			number--;
			if (number < 0) { break; }
			if (s[number] == 'X')
			{
				ret -= 10;
				number--;
			}
			continue;
		}
		if (s[number] == 'C')
		{
			ret += 100;
			number--;
			if (number < 0) { break; }
			if (s[number] == 'X')
			{
				ret -= 10;
				number--;
			}
			continue;
		}
		if (s[number] == 'D')
		{
			ret += 500;
			number--;
			if (number < 0) { break; }
			if (s[number] == 'C')
			{
				ret -= 100;
				number--;
			}
			continue;
		}
		if (s[number] == 'M')
		{
			ret += 1000;
			number--;
			if (number < 0) { break; }
			if (s[number] == 'C')
			{
				ret -= 100;
				number--;
			}
			continue;
		}
	}
	return ret;
}

//罗马数字转整数的main函数
//int main()
//{
//	char s[] = "MCMXCIV";
//	int reception = romanToInt(s);
//	printf("%d\n", reception);
//	return 0;
//}