#include<iostream>
#include<vector>
#include<unordered_map>
#include <ctime>
using namespace std;

class RandomizedSet {
    unordered_map<int, int>* mp;
public:
    RandomizedSet() {
        srand(time(0));
        mp = new unordered_map<int, int>;
    }

    bool insert(int val) {
        (*mp)[val]++;
        if ((*mp)[val] == 2)
        {
            (*mp)[val] = 1;
            return false;
        }
        else
        {
            return true;
        }
    }

    bool remove(int val) {
        (*mp)[val]++;
        if ((*mp)[val] == 2)
        {
            mp->erase(val);
            return true;
        }
        else
        {
            mp->erase(val);
            return false;
        }
    }

    int getRandom() {
        int count = rand() % mp->size();
        auto move = mp->begin();
        while (count--)
        {
            move++;
        }
        return (*move).first;
    }
};