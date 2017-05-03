#include "iostream"

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if(num<0)
            return false;
        return !((num-1)&num)&&(num&0x55555555);
    }
};