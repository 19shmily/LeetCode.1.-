#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//盛水最多的容器

//暴力算法
int _maxArea(int* height, int heightSize) {
	long long area = 0;
	long long tmp_area = 0;
	int side = 0;
	for (int n = 0; n < heightSize; n++)
	{
		for (int m = n + 1; m < heightSize; m++)
		{
			side = height[n] > height[m] ? height[m] : height[n];
			tmp_area = (m - n) * side;
			if (tmp_area > area)
			{
				area = tmp_area;
			}
		}
	}
	return (int)area;
}

//双指针+贪心
int maxArea(int* height, int heightSize) {
	int left = 0;
	int right = heightSize - 1;
	int left_h = 0;
	int right_h = 0;
	int area = height[left] > height[right] ? height[right] : height[left];
	int ret = (right - left) * area;
	while (left < right)
	{
		if (left_h < height[left])
		{
			left_h = height[left];
			area = height[left] > height[right] ? height[right] : height[left];
			ret = (right - left) * area > ret ? (right - left) * area : ret;
		}
		if (height[left] <= height[right])
		{
			left++;
			continue;
		}
		else
		{

			while (left < right)
			{
				if (right_h < height[right])
				{
					right_h = height[right];
					area = height[left] > height[right] ? height[right] : height[left];
					ret = (right - left) * area > ret ? (right - left) * area : ret;
				}
				if (height[left] >= height[right])
				{
					right--;
					continue;
				}
				else
				{
					break;
				}
			}
		}
	}
	return ret;
}

//盛水最多的容器的main函数

//int main()
//{
//	int arr[] = { 1,8,6,2,5,4,8,3,7 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int ret = maxArea(arr, size);
//	printf("%d", ret);
//	return 0;
//}