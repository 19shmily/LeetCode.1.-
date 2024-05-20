#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution_224 {
public:
    int calculate(string s) {
        int ret = 0;
        stack<int>st;
        stack<char>flag;
        string rem;
        s += "+";
        int m = s.size();
        for (int n = 0; n < m; n++)
        {
            if (s[n] == ' ') { continue; }
            else if (s[n] == '(')
            {
                if (!rem.empty()) { st.push(atoi(rem.c_str())); }
                flag.push('(');
            }
            else if (s[n] == ')')
            {
                int tmp = atoi(rem.c_str());
                if (!flag.empty() && flag.top() == '+')
                {
                    tmp = st.top() + tmp;
                    flag.pop();
                    st.pop();
                }
                else if (!flag.empty() && flag.top() == '-')
                {
                    tmp = st.top() - tmp;
                    flag.pop();
                    st.pop();
                }
                flag.pop();
                rem = to_string(tmp);
            }
            else if (s[n] == '+')
            {
                int tmp = atoi(rem.c_str());
                if (!flag.empty() && flag.top() == '+')
                {
                    tmp = st.top() + tmp;
                    flag.pop();
                    st.pop();
                }
                else if (!flag.empty() && flag.top() == '-')
                {
                    tmp = st.top() - tmp;
                    flag.pop();
                    st.pop();
                }
                st.push(tmp);
                flag.push('+');
                rem.clear();
            }
            else if (s[n] == '-')
            {
                int tmp = atoi(rem.c_str());
                if (!flag.empty() && flag.top() == '+')
                {
                    tmp = st.top() + tmp;
                    flag.pop();
                    st.pop();
                }
                else if (!flag.empty() && flag.top() == '-')
                {
                    tmp = st.top() - tmp;
                    flag.pop();
                    st.pop();
                }
                st.push(tmp);
                flag.push('-');
                rem.clear();
            }
            else
            {
                rem += s[n];
            }
        }
        return st.top();
    }
};

//int main()
//{
//    Solution_224 test;
//    string s = "-(2+3)";
//    test.calculate(s);
//
//    return 0;
//}