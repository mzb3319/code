#include "iostream"

using namespace std;

class Solution
{
public:
    double myPow(double x,int n)
    {
        long long m=n;
        if(m==1)
            return x;
        if(m==0)
            return 1;
        bool neg=false;
        if(m<0)
        {
            neg=true;
            m=-m;
        }
        int carry=n%2;
        m/=2;
        double ret=myPow(x,m);
        ret*=ret;
        if(carry)
            ret*=x;
        if(neg)
            ret=1/ret;
        return ret;
    }
};
