#include<iostream>
#include<vector>

using namespace std;

class Solution_66 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n]++;
        while (digits[n] == 10)
        {
            digits[n] = 0;
            n--;
            if (n < 0)
            {
                digits.insert(digits.begin(), 1);
                break;
            }
            digits[n]++;
        }
        return digits;
    }
};