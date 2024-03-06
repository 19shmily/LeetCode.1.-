#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_71 {
public:
    string simplifyPath(string path) {
        int m = path.size();
        vector<int> flag;
        flag.push_back(0);
        for (int n = 0; n < m; n++)
        {
            switch (path[n])
            {
            case '/':
                if (n < m - 1 && path[n + 1] == '/')
                {
                    path.erase(path.begin() + n);
                    n--;
                    m = path.size();
                    continue;
                }
                else if (n != flag.back())
                {
                    flag.push_back(n);
                    continue;
                }
                else
                {
                    continue;
                }
                break;
            case'.':
                if ((n < m - 1 && path[n + 1] == '/') || (n == m - 1))
                {
                    path.erase(path.begin() + n, path.begin() + n + 1);
                    m = path.size();
                    n = flag.back() - 1;
                    continue;
                }
                else if ((n < m - 2 && path[n + 2] == '/') || (path[n + 1] == '.' && n == m - 2))
                {
                    if (flag.size() > 1)
                    {
                        path.erase(path.begin() + flag[flag.size() - 2] + 1, path.begin() + n + 2);
                        flag.pop_back();
                        m = path.size();
                        n = flag.back() - 1;
                        continue;
                    }
                    else
                    {
                        path.erase(path.begin() + n, path.begin() + n + 2);
                        n = flag.back() - 1;
                        m = path.size();
                        continue;
                    }

                }
                else { ; }
            default:
                auto it = find(path.begin() + n, path.end(), '/');
                n = it - path.begin() - 1;
                break;
            }
        }
        if (path.back() == '/' && path.size() != 1)
        {
            path.pop_back();
        }
        return path;
    }
};

//
// 
// int main()
//{
//    Solution test;
//    string recpt = test.simplifyPath("/a/../../b/../c//.//");
//
//    return 0;
//}