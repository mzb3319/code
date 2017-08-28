#include "iostream"
#include "vector"
#include "deque"

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if(n<3)
            return n;
        int a=1,b=2,stair=3;
        while(stair<=n)
        {
            b=a+b;
            a=b-a;
            ++stair;
        }
        return b;
    }
};
