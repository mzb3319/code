#include "iostream"
#include "vector"
#include "deque"

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if(x<2)
            return x;
        long long beg=1,end=x/2;
        while(beg<=end)
        {
            long long mid=(beg+end)/2;
            long long tmp=mid*mid;
            if(tmp==x)
                return mid;
            else if(tmp>x)
                end=mid-1;
            else
                beg=mid+1;
        }
        if(beg*beg>x)
            return end;
        else
            return beg;
    }
};

int main()
{
    Solution s;
    s.mySqrt(INT32_MAX);
    return 0;
}