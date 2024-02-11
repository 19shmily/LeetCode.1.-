#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//最长公共前缀
char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0) 
	{
		return "";
	}
	if (strsSize == 1)
	{
		return strs[0];
	}
	char* ret = (char*)malloc(sizeof(char)*200);
	ret[0] = '\0';
	int n = 0;
	char flag = 0;
	while (1)
	{
		flag = strs[0][n];
		if (flag == '\0')
		{
			return ret;
		}
		for (int i = 1; i < strsSize; i++)
		{
			if (strs[i][n] != flag)
			{
				return ret;
			}
		}
		ret[n] = flag;
		ret[n + 1] = '\0';
		n++;
	}
}

//最长公共前缀的main函数
//int main()
//{
//	char* strs[3] = { "flower","flow","flight" };
//	char* reception = longestCommonPrefix(strs, 3);
//	printf("%s", reception);
//	return 0;
//}