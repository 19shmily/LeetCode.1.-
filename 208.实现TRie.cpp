#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct point
{
    char ch;//记录当前字符
    bool rear;//记录当前是否为已插入字符串的结尾
    struct point* next;//已匹配字符（前缀中含有当前字符）的下一个字符
    struct point* near;//正在匹配的该层字符（前缀中不含有当前字符）的下一个字符
    point() {
        ch = '0';//默认为字符‘0’
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

class Trie {
    struct point* head = NULL;
    int num = 0;
    struct point* work(char c, struct point* p)//判断当前层是否含有字符c
    {                                          //有则返回含有结点的地址，否则返回最后的地址
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
public:
    Trie() {
        head = new struct point();//创建一个头结点
    }

    void insert(string word) {
        int i = word.size();
        struct point* rec = head;
        for (int n = 0; n < i; n++)
        {
            rec = work(word[n], rec);//去当前层寻找字符work[n]
            if (rec->ch == word[n])//判断返回的结点是否为work[n]
            {
                if (n == i - 1) { rec->rear = true; }//判断是否到结尾了，是则将标志rear设为真
                rec = rec->next;//没到word结尾且匹配到了，进入下一层
            }
            else//没匹配上则创建一个新的结点，因为返回的是当前层的最后一个结点，直接插入到他的的near上
            {
                struct point* tmp = new struct point(word[n]);
                if (n == i - 1) { tmp->rear = true; }
                tmp->next = new struct point();//给新结点创建下层结点，为了方便代码书写和规整性
                rec->near = tmp;
                rec = tmp->next;
            }
        }
        return;
    }
    bool search(string word) {
        int i = word.size();
        struct point* rec = head;
        num = word.size();//用num来记录找了多少次了
        for (int n = 0; n < i; n++)
        {
            rec = work(word[n], rec);
            num--;
            if (rec->ch == word[n])//如果匹配成功，开始匹配下一个
            {
                if (!num)//如果全部匹配成功则观察rear，是否为true
                {
                    if (rec->rear)
                    {
                        return true;//是则返回成功
                    }
                    else
                    {
                        return false;//反之失败，因为该结点还有后续结点
                    }
                }
                rec = rec->next;
            }
            else
            {
                return false;//匹配失败直接返回
            }
        }
        return false;
    }
    bool startsWith(string prefix) {
        int i = prefix.size();
        num = prefix.size();
        struct point* rec = head;
        for (int n = 0; n < i; n++)
        {
            rec = work(prefix[n], rec);
            num--;
            if (rec->ch == prefix[n])//这个查找只需要保证每个字符都能匹配成功即可
            {
                if (!num)//只要全部成功直接返回成功
                {
                    return true;
                }
                rec = rec->next;
            }//和search大同小异
            else
            {
                return false;
            }
        }
        return false;
    }
};

int main()
{
    Trie test=Trie();
    test.insert("apple");
    bool b1 = test.search("apple");
    bool b2 = test.startsWith("appl");
    return 0;
}