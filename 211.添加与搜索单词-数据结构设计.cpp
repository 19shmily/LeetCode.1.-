#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//³¬Ê±
class WordDictionary_1 {
    unordered_map<int, vector<string>>*mp;
    bool work(string s1, string s2)
    {
        int m = s1.size();
        for (int n = 0; n < m; n++)
        {
            if (s1[n] != s2[n] && s2[n] != '.') { return false; }
        }
        return true;
    }
public:
    WordDictionary_1() {
        mp = new unordered_map<int, vector<string>>;
    }

    void addWord(string word) {
        int m = word.size();
        if (!mp->count(m)) { mp->insert({ m, vector<string>() }); }
        mp->at(m).push_back(word);
    }

    bool search(string word) {
        int sz = word.size();
        if (!mp->count(sz)) { return false; }
        int m = mp->at(sz).size();
        for (int n = 0; n < m; n++)
        {
            if (work(mp->at(sz)[n], word)) { return true; }
        }
        return false;
    }
};

struct TrieNode {
    vector<TrieNode*> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode*>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c : word) {
        if (node->child[c - 'a'] == nullptr) {
            node->child[c - 'a'] = new TrieNode();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary_2 {
public:
    WordDictionary_2() {
        trie = new TrieNode();
    }

    void addWord(string word) {
        insert(trie, word);
    }

    bool search(string word) {
        return dfs(word, 0, trie);
    }

    bool dfs(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode* child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        }
        else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                TrieNode* child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    TrieNode* trie;
};

int main()
{
    WordDictionary_1 test;
    test.addWord("bad");
    test.addWord("dad");
    test.addWord("mad");
    bool rev = test.search("pad");
    rev = test.search("bad");
    rev = test.search(".ad");
    rev = test.search("b..");
    return 0;
}
