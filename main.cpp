#include "iostream"

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if(x<1)
            return 0;
        int beg=0,end=x;
        while(beg<=end)
        {
            int mid=(beg+end)/2;
            int sqrt=mid*mid;
            if(sqrt==x)
                return mid;
            else if(sqrt<x)
            {
                if((mid+1)*(mid+1)>x)
                    return mid;
                else
                    beg=mid+1;
            }
            else
                end=mid-1;
        }
        return beg;
    }
};