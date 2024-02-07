#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//N字形变换
char* convert(char* s, int numRows) {
    if (numRows == 1)
    {
        return s;
    }
    int number = strlen(s);
    char* tmp = (char*)malloc(sizeof(char) * (number + 1));
    if (tmp == NULL)
    {
        return NULL;
    }
    tmp[number] = '\0';
    int n = 0;

    int multiple1 = 0;
    int multiple2 = 0;
    int flag = 2 * (numRows - 1);
    int i = 0;
    for (n = 0; n < numRows; n++)
    {
        multiple1 = 0;
        multiple2 = 0;
        if (n == 0 || n == numRows - 1)
        {
            while ((n + multiple1 * flag) < number)
            {
                tmp[i] = s[n + multiple1 * flag];
                multiple1++;
                i++;
            }
        }
        else
        {
            while ((n + multiple1 * (flag - 2 * n) + multiple2 * (2 * n)) < number)
            {
                tmp[i] = s[n + multiple1 * (flag - 2 * n) + multiple2 * (2 * n)];
                i++;
                if (multiple1 > multiple2)
                {
                    multiple2++;
                }
                else
                {
                    multiple1++;
                }

            }
        }
    }
    return tmp;
}

//N字形变化的main函数

//int main()
//{
//    char tmp[] = "a";
//    char* p = convert(tmp, 1);
//    printf("%s", p);
//    return 0;
//}
