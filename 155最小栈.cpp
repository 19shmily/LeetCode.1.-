#include<iostream>
#include<stack>
#include<set>
using namespace std;

//�ٷ�������������ջ֮������һ��min_stackջ��ÿ��һ��������min_stackѹ������ջ
//��ջ������Ԫ�صĽ�Сֵ�������ͱ�֤����ÿʱÿ��min_stack��Ķ��ǵ�ǰ����Сֵ
class MinStack {
    stack<int>*sk;
    multiset<int>*arr;
public:
    MinStack() {
        sk = new stack<int>;
        arr = new multiset<int>;
    }

    void push(int val) {
        sk->push(val);
        arr->insert(val);
    }

    void pop() {
        int tmp = sk->top();
        sk->pop();
        arr->erase(arr->find(tmp));
    }

    int top() {
        return sk->top();
    }

    int getMin() {
        return *(arr->begin());
    }
};