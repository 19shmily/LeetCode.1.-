#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution_909 {
    queue<int>q;
    unordered_set<int>rem;
    unordered_map<int, int>mp;
    int ret = 0;
    void work()
    {
        if (q.empty()) { ret = -1; return; }
        ret++;
        int j = q.size();
        for (int i = 0; i < j; i++)
        {
            int tmp = q.front(); q.pop();
            for (int n = 1; n < 7; n++)
            {
                int next = mp[tmp + n] == -1 ? tmp + n : mp[tmp + n];
                if (next == mp.size()) { return; }
                if (!rem.count(next))
                {
                    q.push(next);
                    rem.insert(next);
                }
            }
        }
        work();
        return;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size();
        if (m < 3) { return 1; }
        bool flag = true;
        int j = board[0].size();
        int index = 1;
        for (int n = board.size() - 1; n >= 0; n--)
        {
            if (flag)
            {
                for (int i = 0; i < j; i++)
                {
                    mp[index++] = board[n][i];
                }
                flag = !flag;
            }
            else
            {
                for (int i = j - 1; i >= 0; i--)
                {
                    mp[index++] = board[n][i];
                }
                flag = !flag;
            }
        }
        q.push(1);
        rem.insert(1);
        work();
        return ret;
    }
};

int main()
{
    Solution_909 test;
    vector<vector<int>>board;
    board.push_back({ -1,1,1,1 });
    board.push_back({ -1,7,1,1 });
    board.push_back({ 1,1,1,1 });
    board.push_back({ -1,1,9,1 });
    test.snakesAndLadders(board);
    return 0;
}