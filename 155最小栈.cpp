#include<iostream>
#include<stack>
#include<set>
using namespace std;

//官方题解除了正常的栈之外用了一个min_stack栈，每存一个数，给min_stack压入正常栈
//的栈顶和新元素的较小值，这样就保证了在每时每刻min_stack里的都是当前的最小值
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