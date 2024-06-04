#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

//不知道为啥跑不过4个示例
class Solution_210_1 {
    unordered_map<int, vector<int>>mp;
    unordered_set<int>st;
    vector<int>ing;
    vector<int>ret;
    queue<int>q;
    unordered_set<int>tmp;
    int num = 0;
    bool work()
    {
        if (q.empty()) { return true; }
        int m = q.size();
        for (int n = 0; n < m; n++)
        {
            if (mp.count(q.front()))
            {
                for (auto it = mp[q.front()].begin(); it != mp[q.front()].end(); it++)
                {
                    if (find(mp[*it].begin(), mp[*it].end(), q.front()) != mp[*it].end())
                    {
                        return false;
                    }
                    st.insert(*it);
                    if (!tmp.count(*it))
                    {
                        tmp.insert(*it);
                        q.push(*it);
                    }
                }
            }
            auto fd1 = find(ing.begin(), ing.end(), q.front());
            auto fd2 = find(ret.begin(), ret.end(), q.front());
            if (fd2 == ret.end())
            {
                if (fd1 != ing.end())
                {
                    ing.erase(fd1);
                }
                ing.push_back(q.front());
                st.insert(q.front());
            }
            q.pop();
        }
        return work();
    }
    void repair()
    {
        int n = 0;
        while (ret.size() != num)
        {
            if (find(ret.begin(), ret.end(), n) == ret.end())
            {
                ret.push_back(n);
            }
            n++;
        }
        return;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        num = numCourses;
        int m = prerequisites.size();
        for (int n = 0; n < m; n++)
        {
            mp[prerequisites[n][0]].push_back(prerequisites[n][1]);
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (find(ret.begin(), ret.end(), it->first) == ret.end())
            {
                st.insert(it->first);
                q.push(it->first);
                if (work()) 
                { 
                    reverse(ing.begin(), ing.end());
                    ret.insert(ret.end(), ing.begin(), ing.end()); 
                }
                ing.clear();
                tmp.clear();
            }
        }
        if (ret.size() == st.size())
        {
            repair();
        }
        return ret;
    }
};

//官解，裂开了
class Solution_210_2 {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
    vector<int> visited;
    // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    vector<int> result;
    // 判断有向图中是否有环
    bool valid = true;

public:
    void dfs(int u) {
        // 将节点标记为「搜索中」
        visited[u] = 1;
        // 搜索其相邻节点
        // 只要发现有环，立刻停止搜索
        for (int v : edges[u]) {
            // 如果「未搜索」那么搜索相邻节点
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            // 如果「搜索中」说明找到了环
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        // 将节点标记为「已完成」
        visited[u] = 2;
        // 将节点入栈
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid) {
            return {};
        }
        // 如果没有环，那么就有拓扑排序
        // 注意下标 0 为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution_210_1 test;
    vector<vector<int>>pre;
    pre.push_back({ 1,0 });
    pre.push_back({ 2,0 });
    pre.push_back({ 3,1 });
    pre.push_back({ 3,2 });
    //pre.push_back({ 2,5 });
    //pre.push_back({ 4,5 });
    //pre.push_back({ 5,6 });
    //pre.push_back({ 2,4 });

    test.findOrder(4, pre);
    return 0;
}