#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution_150 {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) { return atoi(tokens[0].c_str()); }
        stack<int>st;
        int m = tokens.size();
        for (int n = 0; n < m; n++)
        {
            if (tokens[n][0] == '+')
            {
                int tmp = st.top();
                st.pop();
                tmp = st.top() + tmp;
                st.pop();
                st.push(tmp);
            }
            else if (tokens[n][0] == '-' && tokens[n].size() == 1)
            {
                int tmp = st.top();
                st.pop();
                tmp = st.top() - tmp;
                st.pop();
                st.push(tmp);
            }
            else if (tokens[n][0] == '*')
            {
                int tmp = st.top();
                st.pop();
                tmp = st.top() * tmp;
                st.pop();
                st.push(tmp);
            }
            else if (tokens[n][0] == '/')
            {
                int tmp = st.top();
                st.pop();
                tmp = st.top() / tmp;
                st.pop();
                st.push(tmp);
            }
            else
            {
                st.push(atoi(tokens[n].c_str()));
            }
        }
        return st.top();
    }
};

int main()
{
    Solution_150 test;
    vector<string>tokens;
    tokens.push_back("10");
    tokens.push_back("6");
    tokens.push_back("9");
    tokens.push_back("3");
    tokens.push_back("+");
    tokens.push_back("-11");
    tokens.push_back("*");
    tokens.push_back("/");
    tokens.push_back("*");
    tokens.push_back("17");
    tokens.push_back("+");
    tokens.push_back("5");
    tokens.push_back("+");
    test.evalRPN(tokens);
    return 0;

}

