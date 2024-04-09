#include<iostream>
#include<vector>
#include<string>
using namespace std;

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

class Trie {
    struct point* head = NULL;
    int num = 0;
    struct point* work(char c, struct point* p)//�жϵ�ǰ���Ƿ����ַ�c
    {                                          //���򷵻غ��н��ĵ�ַ�����򷵻����ĵ�ַ
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
        head = new struct point();//����һ��ͷ���
    }

    void insert(string word) {
        int i = word.size();
        struct point* rec = head;
        for (int n = 0; n < i; n++)
        {
            rec = work(word[n], rec);//ȥ��ǰ��Ѱ���ַ�work[n]
            if (rec->ch == word[n])//�жϷ��صĽ���Ƿ�Ϊwork[n]
            {
                if (n == i - 1) { rec->rear = true; }//�ж��Ƿ񵽽�β�ˣ����򽫱�־rear��Ϊ��
                rec = rec->next;//û��word��β��ƥ�䵽�ˣ�������һ��
            }
            else//ûƥ�����򴴽�һ���µĽ�㣬��Ϊ���ص��ǵ�ǰ������һ����㣬ֱ�Ӳ��뵽���ĵ�near��
            {
                struct point* tmp = new struct point(word[n]);
                if (n == i - 1) { tmp->rear = true; }
                tmp->next = new struct point();//���½�㴴���²��㣬Ϊ�˷��������д�͹�����
                rec->near = tmp;
                rec = tmp->next;
            }
        }
        return;
    }
    bool search(string word) {
        int i = word.size();
        struct point* rec = head;
        num = word.size();//��num����¼���˶��ٴ���
        for (int n = 0; n < i; n++)
        {
            rec = work(word[n], rec);
            num--;
            if (rec->ch == word[n])//���ƥ��ɹ�����ʼƥ����һ��
            {
                if (!num)//���ȫ��ƥ��ɹ���۲�rear���Ƿ�Ϊtrue
                {
                    if (rec->rear)
                    {
                        return true;//���򷵻سɹ�
                    }
                    else
                    {
                        return false;//��֮ʧ�ܣ���Ϊ�ý�㻹�к������
                    }
                }
                rec = rec->next;
            }
            else
            {
                return false;//ƥ��ʧ��ֱ�ӷ���
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
            if (rec->ch == prefix[n])//�������ֻ��Ҫ��֤ÿ���ַ�����ƥ��ɹ�����
            {
                if (!num)//ֻҪȫ���ɹ�ֱ�ӷ��سɹ�
                {
                    return true;
                }
                rec = rec->next;
            }//��search��ͬС��
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