#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

//�Լ��ı���������ʵʱ�临�Ӷ��Ѿ�����O(n)��
class Solution_128_1 {
    int count;
    int ret;
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        count = 0;
        ret = 0;
        for (int n = 0; n < nums.size(); n++)
        {
            if (count == 0)
            {
                count++;
            }
            else 
            {
                if (nums[n] == nums[n - 1]) { continue; }
                else if (nums[n] == nums[n - 1] + 1)
                {
                    count++;
                }
                else
                {
                    ret = ret > count ? ret : count;
                    count = 1;
                }
            }
        }
        return ret = count > ret ? count : ret;
    }
};

//�ٷ��Ĵ��룬������������set����ȥ�أ���ͨ�����õ�count�����жϵ�ǰ������һ�����Ƿ����
//��Ϊ������ģ����Դ��ھͷ���1�������ھͷ���0
//��Ϊÿ�ν���count��ѭ�����Ǵӵ�ǰ����ʼ��������ʱ�临�ӶȺܸ�
//ͨ��count�жϵ�ǰ����һ�Ƿ���ڣ����ھ�����
//��֤��ÿ�ν���ѭ�����Ǵ�һ���������ĵ�һ������ʼ��
//�Ӷ���ʱ�临�ӶȽ�����O(2n)
class Solution_128_2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
