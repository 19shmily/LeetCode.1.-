#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//寻找两个正序数组的中位数

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int number[2000] = { 0 };
    int i = 0;
    int j = 0;
    int count = 0;
    int sentry = 0;
    for (i = 0; i < nums1Size + 1; i++)
    {
        if (i == nums1Size)
        {
            for (j = sentry; j < nums2Size; j++)
            {
                sentry++;
                number[i + j] = nums2[j];
                count++;
            }
            break;
        }

        for (j = sentry; j < nums2Size; j++)
        {
            number[i + j] = (nums1[i] > nums2[j]) ? nums2[j] : nums1[i];
            count++;
            if (nums1[i] < nums2[j])
            {
                break;
            }
            sentry++;
        }
        if (j == nums2Size)
        {
            number[i + j] = nums1[i];
            count++;
        }
    }
    int media1 = count / 2;
    double media2 = (double)count / 2;
    if (media2 - (double)media1)
    {
        return number[media1];
    }
    return ((double)(number[media1] + number[media1 - 1])) / 2;
}