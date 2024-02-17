#include<iostream>
#include<vector>
#include<string>
using namespace std;

void creat(int left, int right, int n, vector<string>& ret, string& now) 
{
	if (right > left)
	{
		return;
	}
	if (left == n && right == n)
	{
		ret.push_back(now);
		return;
	}
	if (left < n)
	{
		now.push_back('(');
		creat(left + 1, right, n, ret, now);
		now.pop_back();
	}
	if (right < n)
	{
		now.push_back(')');
		creat(left, right + 1, n, ret, now);
		now.pop_back();
	}
}

//À¨ºÅÉú³É
class Solution_22 {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>ret;
		string str;
		creat(0, 0, n, ret, str);
		return ret;
	}
};

