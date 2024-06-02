#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution_399 {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>>mp;
        int m = equations.size();
        vector<double>ret;
        bool flag = false;
        for (int n = 0; n < m; n++)
        {
            mp[equations[n][0]][equations[n][1]] = values[n];
            mp[equations[n][1]][equations[n][0]] = 1 / values[n];
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                if ((*it).second.count(equations[n][0]))
                {
                    if (mp[(*it).first].count(equations[n][1]))
                    {
                        continue;
                    }
                    else
                    {
                        mp[(*it).first][equations[n][1]] = (*it).second[equations[n][0]] * values[n];
                        mp[equations[n][1]][(*it).first] = 1 / mp[(*it).first][equations[n][1]];
                        flag = true;
                        break;
                    }
                }
                if ((*it).second.count(equations[n][1]))
                {
                    if (mp[(*it).first].count(equations[n][0]))
                    {
                        continue;
                    }
                    else
                    {
                        mp[(*it).first][equations[n][0]] = (*it).second[equations[n][1]] / values[n];
                        mp[equations[n][0]][(*it).first] = 1 / mp[(*it).first][equations[n][0]];
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) { flag = false; n = -1; }
        }
        m = queries.size();
        for (int n = 0; n < m; n++)
        {
            if (mp[queries[n][0]].count(queries[n][1]))
            {
                ret.push_back(mp[queries[n][0]][queries[n][1]]);
            }
            else { ret.push_back(-1); }
        }
        return ret;
    }
};

//int main()
//{
//    Solution_399 test;
//    vector<vector<string>>equations;
//    vector<double>values;
//    vector<vector<string>>queries;
//    vector<string>tmp;
//    equations.push_back({ "a","b" });
//    equations.push_back({ "b","c" });
//    values.push_back(2);
//    values.push_back(3);
//    queries.push_back({ "a","c" });
//    queries.push_back({ "b","a" });
//    queries.push_back({ "a","e" });
//    queries.push_back({ "a","a" });
//    queries.push_back({ "x","x" });
//    test.calcEquation(equations, values, queries);
//    return 0;
//}