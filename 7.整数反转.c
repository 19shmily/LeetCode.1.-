#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//整数反转

int reverse(int x) {
    int a = 0;
    int flag = 0;
    long long judg = 0;
    do
    {
        if (!(x % 10) && flag == 0)
        {
            continue;
        }
        else
        {
            flag = 1;
        }
        if (a < INT_MIN / 10 || a > INT_MAX / 10) {
            return 0;
        }

        a = a * 10 + x % 10;

    } while (x /= 10);
    return a;
}

//整数反转的main函数

//int main()
//{
//    int n = reverse(2147483647);
//    printf("%d", n);
//    return 0;
//}