#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
    unordered_map<int, int>mp;
    vector<int>arr;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        auto it = find(arr.begin(), arr.end(), key);
        if (it != arr.end())
        {
            arr.erase(it);
            arr.push_back(key);
            return mp[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) {
        auto it = find(arr.begin(), arr.end(), key);
        if (it == arr.end())
        {
            if (mp.size() == size)
            {
                mp.erase(mp.find(arr[0]));
                arr.erase(arr.begin());
            }
            arr.push_back(key);
        }
        else
        {
            arr.erase(it);
            arr.push_back(key);
        }
        mp[key] = value;
        return;
    }
};

int main()
{
    int n = 0;
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(2, 1);
    lRUCache->put(1, 1); 
    lRUCache->put(2, 3);
    lRUCache->put(4, 1);
    n=lRUCache->get(1);   
    n=lRUCache->get(2);   
   
    return 0;
}