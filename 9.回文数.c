#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//������

bool isPalindrome(int x) {
    int a = 0;
    int judg = x;
    if (x < 0)
    {
        return false;
    }
    else if (x == 0)
    {
        return true;
    }
    else
    {
        do
        {
            if (a > INT_MAX / 10)
            {
                return 0;
            }
            a = a * 10 + x % 10;
        } while (x /= 10);
        if (judg == a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

//��������main����

//int main()
//{
//    bool a = isPalindrome(121);
//    printf("%d", a);
//    return 0;
//}