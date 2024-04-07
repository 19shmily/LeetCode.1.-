#include<iostream>
#include<vector>
#include<map>
using namespace std;

//官方题解，拓补排序没接触过之前
class Solution_207_1 {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};

//下面自己写的，已凉，只能跑过连续学习的
//多个单独学习就跑不过
class Solution_207_0 {
    multimap<int, int>mp;
    multimap<int, int>rem;
    int count = 0;
    void work(int num)
    {
        count--;
        auto it = mp.find(num);
        if (it != mp.end())
        {
            int num1 = (*it).first, num2 = (*it).second;
            while (num1 == (*it).first)
            {
                mp.erase(it);
                work(num2);
                it = mp.find(num);
                if (it == mp.end())
                {
                    if (rem.find(num2) != rem.end())
                    {
                        count = INT_MAX;
                        return;
                    }
                    else
                    {
                        return;
                    }
                }
                num2 = (*it).second;
            }
        }
        else
        {
            return;
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if (n == 0) { return true; }
        for (int i = 0; i < n; i++)
        {
            rem.insert({ prerequisites[i][0],prerequisites[i][1] });
        }
        for (int i = 0; i < n; i++)
        {
            count = numCourses;
            mp = rem;
            work(prerequisites[i][0]);
            if (count == 0)
            {
                return true;
            }
        }
        return false;
    }
};



int main()
{
    vector<vector<int>>prerequisites;
    prerequisites.push_back({ 0,1 });
   // prerequisites.push_back({ 0,1 });
    Solution_207 test;
    test.canFinish(2, prerequisites);
    return 0;
}