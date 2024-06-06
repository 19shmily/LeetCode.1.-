#include<iostream>
#include<string>
using namespace std;

//笨办法
class Solution_190_1 {
public:
    uint32_t reverseBits(uint32_t n) {
        double num = n;
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++)
        {
            n >>= 1;
            num /= 2;
            if (n != num)
            {
                ret += pow(2, 31 - i);
            }
            num = n;
        }
        return ret;
    }
};

//高贵的位运算分治
//1.首先，我们知道 （单个二进制码 & 1) = 其本身，所以对于参数 M1，可以看成是用来将一串二进制码的奇数位提取出来；
//2.接着，n >> 1，右移，可以看作是将 n 上原来的偶数位变成奇数位，为什么不说奇数位也变成偶数位，是因为右移将第一个奇数位移除了；
//3.其次，(n >> 1) & M1，就是如1所述，将（n >> 1）的奇数位提取出来，也就是原 n 的偶数位；
//4.再次，(n & M1) << 1，就是先将 n 的奇数位提出来，然后左移，将其变成偶数位；
//5.然后，奇数位(原 n 的偶数位) | 偶数位(原 n 的奇数位)，相或，就达到了原 n 的奇数位和偶数位互换的目的；
class Solution_190_2 {
private:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

public:
    uint32_t reverseBits(uint32_t n) {
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
};


int main()
{
    Solution_190_1 test;
    test.reverseBits(964176192);
    return 0;
}
