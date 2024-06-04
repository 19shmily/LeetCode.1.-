#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

//��֪��Ϊɶ�ܲ���4��ʾ��
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

//�ٽ⣬�ѿ���
class Solution_210_2 {
private:
    // �洢����ͼ
    vector<vector<int>> edges;
    // ���ÿ���ڵ��״̬��0=δ������1=�����У�2=�����
    vector<int> visited;
    // ��������ģ��ջ���±� 0 Ϊջ�ף�n-1 Ϊջ��
    vector<int> result;
    // �ж�����ͼ���Ƿ��л�
    bool valid = true;

public:
    void dfs(int u) {
        // ���ڵ���Ϊ�������С�
        visited[u] = 1;
        // ���������ڽڵ�
        // ֻҪ�����л�������ֹͣ����
        for (int v : edges[u]) {
            // �����δ��������ô�������ڽڵ�
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            // ����������С�˵���ҵ��˻�
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        // ���ڵ���Ϊ������ɡ�
        visited[u] = 2;
        // ���ڵ���ջ
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        // ÿ����ѡһ����δ�������Ľڵ㣬��ʼ���������������
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid) {
            return {};
        }
        // ���û�л�����ô������������
        // ע���±� 0 Ϊջ�ף������Ҫ�����鷴�����
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