#include<iostream>
#include<vector>
#include<string>
using namespace std;


//�Ż������ˣ��Ѿ������ˣ�����Ŀǰ��2024.4.18���Ĳ���������ʣ�����޷�ͨ��
//�����֮ǰ��ǰ׺���⣨208�����ϳ�ǰ׺�������ϵز�ѯ����ɾ��ĩβ���ý��
struct point
{
    char ch;//��¼��ǰ�ַ�
    bool rear;//��¼��ǰ�Ƿ�Ϊ�Ѳ����ַ����Ľ�β
    struct point* next;//��ƥ���ַ���ǰ׺�к��е�ǰ�ַ�������һ���ַ�
    struct point* near;//����ƥ��ĸò��ַ���ǰ׺�в����е�ǰ�ַ�������һ���ַ�
    point() {
        ch = '0';//Ĭ��Ϊ�ַ���0��
        rear = false;
        near = NULL;
        next = NULL;
    }
    point(char c) {
        ch = c;
        rear = false;
        near = NULL;
        next = NULL;
    }
};
struct point* head = NULL;
int num = 0;
struct point* work(char c, struct point* p)
{                
    if (!p) { return NULL; }
    if (p->ch == c)
    {
        return p;
    }
    while (p->near)
    {
        p = p->near;
        if (p->ch == c)
        {
            return p;
        }
    }
    return p;
}
void Trie() {
    head = new struct point();//����һ��ͷ���
}

void insert(string word) {
    int i = word.size();
    struct point* now = head;
    for (int n = 0; n < i; n++)
    {
        struct point* rec = work(word[n], now->next);
        if (!rec)
        {
            now->next = new struct point(word[n]);
            if (n == i - 1) { now->next->rear = true; }
            now = now->next;
        }
        else if (rec->ch == word[n])
        {
            if (n == i - 1) { rec->rear = true; }
            now = rec;
        }
        else
        {
            struct point* tmp = new struct point(word[n]);
            if (n == i - 1) { tmp->rear = true; }
            rec->near = tmp;
            now = tmp;
        }
    }
    return;
}
class Solution_212 {
    int up = 0, down = 0, left = 0, right = 0;
    vector<string>ret;
    string rem;
    void work(vector<vector<char>> board, struct point* parent, struct point* tmp, int x, int y)
    {
        struct point* front = NULL;
        while (tmp)
        {
            if (!tmp->next && !tmp->rear)
            {
                if (!front)
                {
                    parent->next = tmp->near;
                    delete tmp;
                    tmp = parent->next;
                }
                else
                {
                    front->near = tmp->near;
                    delete tmp;
                    tmp = front->near;
                }
                continue;
            }
            if (board[x][y] == tmp->ch)
            {
                rem.push_back(board[x][y]);
                if (tmp->rear)
                {
                    ret.push_back(rem);
                    tmp->rear = false;
                }
                board[x][y] = 0;
                if (x + 1 < down)
                {
                    work(board, tmp, tmp->next, x + 1, y);
                }
                if (x - 1 > up)
                {
                    work(board, tmp, tmp->next, x - 1, y);
                }
                if (y + 1 < right)
                {
                    work(board, tmp, tmp->next, x, y + 1);
                }
                if (y - 1 > left)
                {
                    work(board, tmp, tmp->next, x, y - 1);
                }
                rem.pop_back();
            }
            front = tmp;
            tmp = tmp->near;
        }
        return;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = words.size();
        up = -1, down = board.size(), left = -1, right = board[0].size();
        Trie();
        for (int n = 0; n < m; n++)
        {
            insert(words[n]);
        }
        for (int x = 0; x < down; x++)
        {
            for (int y = 0; y < right; y++)
            {
                work(board, head, head->next, x, y);
                rem.clear();
            }
        }
        return ret;
    }
};

int main()
{
    Solution_212 test;
    vector<vector<char>>board;
    board.push_back({ 'o','a','a','n' });
    board.push_back({ 'e', 't', 'a', 'e' });
    board.push_back({ 'i', 'h', 'k', 'r' });
    board.push_back({ 'i', 'f', 'l', 'v' });
    vector<string>words;
    words.push_back("oath");
    words.push_back("pea");
    words.push_back("eat");
    words.push_back("rain");
    words.push_back("hklf");
    words.push_back("hf");
    test.findWords(board, words);

    return 0;
}