#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//无重复字符的最长子串

int lengthOfLongestSubstring(char* s) {
    int a = strlen(s);
    char tmp[100] = { 0 };
    int i = 0;
    int j = 0;
    int n = 0;
    char tp[2] = { 0 };
    int return_number = 0;
    if (a == 1)
    {
        return 1;
    }
    for (i = 0; i < a; i++)
    {
        tmp[0] = s[i];
        tmp[1] = '\0';
        n = 1;
        for (j = i + 1; j < a; j++)
        {
            tp[0] = s[j];
            if (!strstr(tmp, tp))
            {
                tmp[j - i] = s[j];
                tmp[j - i + 1] = '\0';
                n++;
                return_number = (n > return_number) ? n : return_number;
            }
            else
            {
                break;
            }
        }
    }
    return return_number = (n > return_number) ? n : return_number;
}