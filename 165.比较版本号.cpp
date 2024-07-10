#include<iostream>
#include<string>

using namespace std;

class Solution_165 {
    int work(string& version1, int& n, int m)
    {
        long long ret = 0;
        while (n < m && version1[n] != '.')
        {
            ret = ret * 10 + version1[n] - '0';
            n++;
        }
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        int m1 = version1.size(), m2 = version2.size();
        int index1 = 0, index2 = 0;
        while (1)
        {
            long long num1 = work(version1, index1, m1);
            long long num2 = work(version2, index2, m2);
            if (num1 == num2)
            {
                if (index1 != m1) { index1++; }
                if (index2 != m2) { index2++; }
                if (index1 == m1 && index2 == m2) { return 0; }
            }
            else if (num1 < num2) { return -1; }
            else { return 1; }
        }
        return 0;
    }
};

//int main()
//{
//    Solution_165 test;
//    string s1 = "1.01";
//    string s2 = "1.001";
//    test.compareVersion(s1, s2);
//    return 0;
//}
