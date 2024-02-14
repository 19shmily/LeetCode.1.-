#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

//电话号码的字母组合
void build(vector<string>& alphabet)
{
    alphabet.push_back("0");
    alphabet.push_back("0");
    alphabet.push_back("abc");
    alphabet.push_back("def");
    alphabet.push_back("ghi");
    alphabet.push_back("jkl");
    alphabet.push_back("mno");
    alphabet.push_back("pqrs");
    alphabet.push_back("tuv");
    alphabet.push_back("wxyz");
}

void insert(vector<string>& vet, int num)
{
    int size = vet.size();
    for (int n = 0; n < num-1; n++)
    {
        for (int m = 0; m < size; m++)
        {
            vet.push_back(vet[m]);
        }
    }
}

class Solution_17 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ret;
        if (!digits.size())
        {
            return ret;
        }
        vector<string>alphabet;
        build(alphabet);
        for (int i = 0; i < alphabet[digits[0] - '0'].size(); i++)
        {
            std::stringstream ss;
            ss << alphabet[digits[0] - '0'][i];
            std::string str = ss.str();
            ret.push_back(str);
        }
        for (int i = 1; i < digits.size(); i++)
        {
            int m = 0;
            int size = ret.size();
            insert(ret, alphabet[digits[i] - '0'].size());
            for (int n = 0; n < ret.size(); )
            {
                if (m == size)
                {
                    m = 0;
                }
                int temp = size;
                while (temp--)
                {
                    ret[n].push_back(alphabet[digits[i] - '0'][m]);
                    n++;
                } 
                m++;
            }
        }
        return ret;
    }
};

//电话号码的字母组合的main函数
//int main()
//{
//    string str("234");
//    Solution_17 test;
//    vector<string> recept = test.letterCombinations(str);
//    int n = 0;
//    for (vector<string>::iterator it = recept.begin(); it < recept.end(); it++)
//    {
//        cout << recept[n] << endl;
//    	 n++;
//    }
//
//    system("pause");
//    return 0;
//}