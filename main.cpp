#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& A)
    {
        if(A.size()<3)
            return 0;
        int ret=0;
        int count=1;
        int diff=A[1]-A[0];
        for(int i=1;i<A.size();i++)
        {
            int d=A[i]-A[i-1];
            if(d==diff)
            {
                count++;
                if(i==A.size()-1&&count>=3)
                    ret+=(count-1)*(count-2)/2;
            }
            else
            {
                if(count>=3)
                {
                    ret+=(count-1)*(count-2)/2;
                }
                diff=d;
                count=2;
            }
        }
        return ret;
    }
};