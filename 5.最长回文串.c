#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//最长回文串

char* longestPalindrome(char* s) {
    int flag = 0;
    int number = 0;
    int max_number = 1;
    int right_flag = strlen(s) - 1;
    int left_flag = 0;
    int right = 0;
    int left = 0;
    for (; left_flag < right_flag; left_flag++)
    {
        for (right_flag = strlen(s) - 1; left_flag < right_flag; right_flag--)
        {
            number = 0;
            left = left_flag;
            right = right_flag;
            while (s[left] == s[right] && left < right)
            {
                left++; right--;
                number += 2;
            }
            if (right == left && max_number <= number)
            {
                number++;
                flag = left_flag;
                max_number = number;
                break;
            }
            else if (right < left && max_number <= number)
            {
                flag = left_flag;
                max_number = number;
                break;
            }
        }
        right_flag = strlen(s) - 1;
    }
    char* tmp = (char*)malloc(sizeof(char) * (max_number + 1));
    if (tmp == NULL)
    {
        return 0;
    }
    if (max_number)
    {
        for (int i = 0; i < max_number; i++)
        {
            tmp[i] = s[flag];
            tmp[i + 1] = '\0';
            flag++;
        }
        return tmp;
    }
    else
    {
        tmp[0] = s[0];
        return tmp;

    }
    return NULL;
}

//最长回文串的main函数

//int main()
//{
//    char tmp[] = "aba";
//    char* p = longestPalindrome(tmp);
//    printf("%s", p);
//}
