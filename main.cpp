#include "iostream"

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int beg=1,end=32;
        while(beg<end)
        {
            uint32_t a=1<<(32-beg),b=1<<(32-end);
            a&=n;
            b&=n;
            if(a>>(32-beg)!=b>>(32-end))
            {
                n^=(1<<(32-beg));
                n^=(1<<(32-end));
            }
            ++beg;
            --end;
        }
        return n;
    }
};