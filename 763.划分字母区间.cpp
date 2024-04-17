#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

class Solution_763 {
    vector<int>ret;
    vector<int>rem;
    vector<int>frist;
    void adjust(int num, int pos)
    {
        for (int n = 0; n < 26; n++)
        {
            if (frist[num] < rem[n] && rem[n] < pos)
            {
                rem[n] = pos;
            }
        }
    }
public:
    vector<int> partitionLabels(string s) {
        rem.resize(26, -1);
        frist.resize(26, -1);
        int m = s.size();
        for (int n = 0; n < m; n++)
        {
            if (frist[s[n] - 'a'] == -1) { frist[s[n] - 'a'] = n; }
            rem[s[n] - 'a'] = n;
            adjust(s[n] - 'a', n);
        }
        set<int>cut;
        for (int n = 0; n < 26; n++)
        {
            cut.insert(rem[n]);
        }
        auto it = cut.begin();
        for (; it != cut.end(); it++)
        {
            if (it == cut.begin())
            {
                if (*it == -1) { continue; }
                else
                {
                    ret.push_back(*it + 1);
                }
            }
            else
            {
                auto tmp = it;
                tmp--;
                ret.push_back(*it - *tmp);
                tmp++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution_763 test;
    string s = "ntswuqqbidunnixxpoxxuuupotaatwdainsotwvpxpsdvdbwvbtdiptwtxnnbtqbdvnbowqitudutpsxsbbsvtipibqpvpnivottsxvoqqaqdxiviidivndvdtbvadnxboiqivpusuxaaqnqaobutdbpiosuitdnopoboivopaapadvqwwnnwvxndpxbapixaspwxxxvppoptqxitsvaaawxwaxtbxuixsoxoqdtopqqivaitnpvutzchkygjjgjkcfzjzrkmyerhgkglcyffezmehjcllmlrjghhfkfylkgyhyjfmljkzglkklykrjgrmzjyeyzrrkymccefggczrjflykclfhrjjckjlmglrmgfzlkkhffkjrkyfhegyykrzgjzcgjhkzzmzyejycfrkkekmhzjgggrmchkeclljlyhjkchmhjlehhejjyccyegzrcrerfzczfelzrlfylzleefgefgmzzlggmejjjygehmrczmkrc";
    test.partitionLabels(s);
}