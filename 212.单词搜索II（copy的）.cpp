#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;


struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        this->word = "";
    }
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;

    for (auto c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }

    node->word = word;
}

class Solution_212_copy {
public:
    int dirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, set<string>& res) {
        char ch = board[x][y];

        if (root == nullptr || !root->children.count(ch)) {
            return false;
        }

        TrieNode* nxt = root->children[ch];
        if (nxt->word.size() > 0) {
            res.insert(nxt->word);
            nxt->word = "";
        }
        if (!nxt->children.empty()) {
            board[x][y] = '#';
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                    if (board[nx][ny] != '#') {
                        dfs(board, nx, ny, nxt, res);
                    }
                }
            }
            board[x][y] = ch;
        }
        if (nxt->children.empty()) {
            root->children.erase(ch);
        }

        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto& word : words) {
            insertTrie(root, word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }
        for (auto& word : res) {
            ans.emplace_back(word);
        }

        return ans;
    }
};

int main()
{
    Solution_212_copy test;
    vector<vector<char>>board;
    board.push_back({ 'o','a','a','n' });
    board.push_back({ 'e', 't', 'a', 'e' });
    board.push_back({ 'i', 'h', 'k', 'r' });
    board.push_back({ 'i', 'f', 'l', 'v' });
    vector<string>words;
    words.push_back("aaaa");
    words.push_back("aaab");
    words.push_back("aaac");
    words.push_back("aabv");
    words.push_back("aabe");
    words.push_back("aaca");
    test.findWords(board, words);

    return 0;
}