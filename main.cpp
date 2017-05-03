#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool isUgly(int num)
    {
        if(!num)
            return false;
        while(!(num%2))
            num/=2;
        while(!(num%3))
            num/=3;
        while(!(num%5))
            num/=5;
        if(num==1)
            return true;
        return false;
    }
};