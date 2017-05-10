#include "iostream"

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t flag=0;
        uint32_t ret=0;
        for(int i=0;i<32;i++)
        {
            flag=n&1;
            ret=ret<<1;
            ret=ret|flag;
            n=n>>1;
        }
        return ret;
    }
};