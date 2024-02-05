#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//两数之和

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int j = 0;
    int* result = NULL;
    *returnSize = 2;
    result = (int*)malloc(sizeof(int) * 2);
    for (i = 0; i < numsSize; i++)
    {
        *result = i;
        int temp = nums[i];
        for (j = i + 1; j < numsSize; j++)
        {
            if (target == (temp + nums[j]))
            {
                *(result + 1) = j;

                return result;
            }
        }
    }
    return NULL;
}