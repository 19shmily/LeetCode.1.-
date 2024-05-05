#include<iostream>
#include<vector>

using namespace std;

//³¬Ê±
class Solution_134_1 {
    bool work(vector<int>& gas, vector<int>& cost, int n, int m)
    {
        int flag = n;
        int i = 0;
        int sum = 0;
        do
        {
            i = n % m;
            sum += (gas[i] - cost[i]);
            if (sum < 0)
            {
                return false;
            }
            n++;
        } while (flag != n % m);
        return true;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int m = gas.size();
        for (int n = 0; n < m; n++)
        {
            if (work(gas, cost, n, m))
            {
                return n;
            }
        }
        return -1;
    }
};

//ÔÙÀ´
class Solution_134_2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int m = cost.size();
        int sum1 = 0, sum2 = 0;
        int ret = -1;
        int tmp = 0;
        bool flag = false;
        for (int n = 0; n < m; n++)
        {
            sum1 += gas[n]; sum2 += cost[n];
            int dir = gas[n] - cost[n];
            if (dir >= 0)
            {
                if (!flag)
                {
                    ret = n;
                }
                flag = true;
            }
            if (flag)
            {
                tmp += dir;
                if (tmp < 0)
                { 
                    tmp = 0;
                    flag = false; 
                }
            }
        }
        if (flag && sum1 >= sum2) { return ret; }
        else { return -1; }
    }
};


int main()
{
    Solution_134_2 test;
    vector<int>gas;
    vector<int>cost;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);
    cost.push_back(1);
    cost.push_back(2);
    test.canCompleteCircuit(gas, cost);
    return 0;
}