#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//正则表达式匹配

////自己写的，已挂，未通过
//bool isMatch(char* s, char* p) {
//    int s_ptr = strlen(s) - 1;
//    int p_ptr = strlen(p) - 1;
//    char flag = 0;
//    while (1)
//    {
//        if ((s_ptr < 0 && p_ptr >= 0) || (s_ptr >= 0 && p_ptr < 0))
//        {
//            return false;
//        }
//        else if (s[s_ptr] == p[p_ptr] && s_ptr == 0 && p_ptr == 0)
//        {
//            return true;
//        }
//        else if (p[p_ptr] == '.')
//        {
//            s_ptr--;
//            p_ptr--;
//            continue;
//        }
//        else if (p[p_ptr] == '*' && p[p_ptr - 1] == '.')
//        {
//            if (p_ptr - 1 == 0)
//            {
//                return true;
//            }
//            while (p[p_ptr - 2] != s[s_ptr])
//            {
//                s_ptr--;
//                if (s_ptr < 0)
//                {
//                    while (p[p_ptr] == '*')
//                    {
//                        p_ptr -= 2;
//                        if (p_ptr < 0)
//                        {
//                            return true;
//                        }
//                    }
//                }
//            }
//            p_ptr -= 2;
//        }
//        else if (p[p_ptr] == '*')
//        {
//            while (s[s_ptr] == p[p_ptr-1])
//            {
//                s_ptr--;
//                if (s_ptr < 0)
//                {
//                    while (p[p_ptr] == '*')
//                    {
//                        p_ptr -= 2;
//                        if (p_ptr < 0)
//                        {
//                            return true;
//                        }
//                    }
//                    return false;
//                }
//            }
//            if (s_ptr != 0 && p_ptr - 1 == 0)
//            {
//                return false;
//            }
//            p_ptr -= 2;
//            continue;
//        }
//        else if (s[s_ptr] == p[p_ptr])
//        {
//            s_ptr--;
//            p_ptr--;
//            continue;
//        }
//        else
//        {
//            return false;
//        }
//    }
//}


//网上拷贝的
bool isMatch(char* s, char* p) {
    if (!*p) 
    {
        return !*s;
    }
    bool first_match = *s && (*s == *p || *p == '.');
    if (*(p + 1) == '*') 
    {
        return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
    }
    else 
    {
        return first_match && isMatch(++s, ++p);
    }
}

//正则表达式匹配main函数

//int main()
//{
//    char s[] = "aaa";
//    char p[] = "ab*a*c*a";
//    bool ret = isMatch(s, p);
//    printf("%d", ret);
//    return 0;
//}