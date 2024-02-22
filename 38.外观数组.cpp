#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution_38 {
public:
    string countAndSay(int n) {
        string str;
        str.push_back(49);
        for (int i = 1; i < n; i++)
        {
            string tmp = str;
            int num = 1;
            str.erase();
            for (int j = 1; j < tmp.size(); j++)
            {
                if (tmp[j] != tmp[j - 1])
                {
                    str.push_back(num + 48);
                    str.push_back(tmp[j - 1]);
                    num = 1;
                    continue;
                }
                num++;
            }
            str.push_back(num + 48);
            str.push_back(tmp[tmp.size() - 1]);
        }
        return str;
    }
};

//int main()
//{
//    Solution_38 test;
//    string rec = test.countAndSay(5);
//    cout << rec << endl;
//
//    system("pause");
//    return 0;
//}