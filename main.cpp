#include "iostream"

using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int pre=0,i=2;
        for(;i*i<num;i*=i)
        {
            pre=i;
        }
        if(i==num)
            return true;
        int ret=core(num,pre+1,i-1);
        return ret*ret==num;
    }
private:
    int core(int num,int beg,int end)
    {
        if(beg>end)
            return beg;
        int mid=(beg+end)/2;
        int pow=mid*mid;
        if(pow==num)
            return mid;
        else if(pow<num)
            return core(num,mid+1,end);
        else
            return core(num,beg,mid-1);
        return beg;
    }
};
/*上边的也存在溢出问题，要把int提升为long long
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long i=0;
        while(i*i<num)
            i++;
        return i*i==num;
    }
};
 */