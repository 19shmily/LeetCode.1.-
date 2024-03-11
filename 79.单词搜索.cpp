#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution_79 {
    int up;
    int down;
    int left;
    int right;
    bool work(vector<vector<char>>& board, string& word, map<int, vector<int>>& tmp, int n, int x, int y)
    {
        if (find(tmp[x].begin(), tmp[x].end(), y)!=tmp[x].end())
        {
            return false;
        }
        else
        {
            tmp[x].push_back(y);
        }
        if (board[x][y] == word[n])
        {
            if (n == word.size() - 1)
            {
                return true;
            }
            if (x > up)
            {
                if (work(board, word, tmp, n + 1, x - 1, y))
                {
                    return true;
                }
            }
            if (y < right)
            {
                if (work(board, word, tmp, n + 1, x, y + 1))
                {
                    return true;
                }
            }
            if (x < down)
            {
                if (work(board, word, tmp, n + 1, x + 1, y))
                {
                    return true;
                }
            }
            if (y > left)
            {
                if (work(board, word, tmp, n + 1, x, y - 1))
                {
                    return true;
                }
            }
        }
        tmp[x].pop_back();
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        up = 0;
        down = board.size() - 1;
        left = 0;
        right = board[0].size() - 1;
        map<int, vector<int>>tmp;
        for (int i = 0; i <= down; i++)
        {
            for (int j = 0; j <= right; j++)
            {
                if (work(board, word, tmp, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//int main()
//{
//    Solution test;
//    vector<vector<char>>board;
//    string word;
//    vector<char>tmp;
//    tmp.push_back('A');
//    tmp.push_back('A');
//    //tmp.push_back('C');
//    //tmp.push_back('E');
//    //board.push_back(tmp);
//    //tmp.clear();
//    //tmp.push_back('S');
//    //tmp.push_back('F');
//    //tmp.push_back('C');
//    //tmp.push_back('S');
//    //board.push_back(tmp);
//    //tmp.clear();
//    //tmp.push_back('A');
//    //tmp.push_back('D');
//    //tmp.push_back('E');
//    //tmp.push_back('E');
//    board.push_back(tmp);
//    tmp.clear();
//    word = "AAA";
//    bool recpt = test.exist(board, word);
//
//    return 0;
//}