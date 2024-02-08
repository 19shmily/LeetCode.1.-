#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//�ַ���ת������

int myAtoi(char* s) {
    int i = 0;
    int out = 0;
    int pol = 1;
    int len = strlen(s);

    if (len == 0) 
    {
        return 0;
    }
    while (s[i] == ' ') i++;  //ɾ���ո�
    if (s[i] == '-')
    {         //�ж�����
        pol = -1;
        i++;
    }
    else if (s[i] == '+') 
    {
        pol = 1;
        i++;
    }
    else 
    {
        pol = 1;
    }

    while (s[i] != '\0') 
    {
        if (s[i] < '0' || s[i]>'9') 
        { //�Ƿ��ַ����
            i++;
            break;
        }
        if (out > INT_MAX / 10)
        {
            return (pol > 0 ? INT_MAX : INT_MIN);  //Խ���ж�
        }
        if (out == INT_MAX / 10)
        {
            if (pol > 0 && s[i] > '7') 
            {
                return INT_MAX;
            }
            else if (pol < 0 && s[i] >= '8')
            {
                return INT_MIN;
            }
        }
        //����������дӦ����out=10*out+(s[i]-'0')��֮�����ȼ�ȥ'0',
        //��Ϊ�˷�ֹ10*out+s[i]Խ��
        out = 10 * out - '0' + s[i];
        //���ڱ���û�в�����64λ�Ĵ洢���ݣ����ԷǷ��жϿ��Ը��Ӽ�
        //����ֱ�ӽ�out����Ϊlong�ͣ�ֱ���жϼ���
        //if(pol*out>INT_MAX) return INT_MAX;
        //if(pol*out<INT_MIN) return INT_MIN;
        i++;
    }
    out = out * pol;
    return out;
}

//�ַ���ת��������main����

//int main()
//{
//	int a = myAtoi("123a");
//	printf("%d", a);
//	return 0;
//}
