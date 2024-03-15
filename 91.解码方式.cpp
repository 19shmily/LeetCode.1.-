#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution_91 {
public:
    int numDecodings(string s) {
        if (s[0] == '0' || (s[1] == '0' && s[0] > '2')) { return 0; }
        if (s.size() < 2) { return 1; }
        vector<int>rem(s.size());
        rem[0] = 1;
        rem[1] = 1;
        if ((s[1] - '0') + (s[0] - '0') * 10 < 27 && s[1] != '0')
        {
            rem[1] += 1;
        }
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                rem[i] = rem[i - 1];
            }
            if ((s[i] - '0') + (s[i - 1] - '0') * 10 < 27 && s[i - 1] != '0')
            {
                rem[i] += rem[i - 2];
            }
        }
        return rem.back();
    }
};

int main()
{
    Solution_91 test;
    string nums;
    nums.push_back('2');
    nums.push_back('1');
    nums.push_back('0');
    nums.push_back('1');
    //nums.push_back('2');
    //nums.push_back('3');
    //nums.push_back('4');

    test.numDecodings(nums);
    return 0;
}