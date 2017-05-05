#include "iostream"
#include "unordered_set"
#include "cmath"

using namespace std;


class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        int sum=1;
        int i=2;
        double min=sqrt(num);
        if(min/1.0>0.00000001)
            min++;
        int m=min;
        while(i<m)
        {
            if(num%i==0)
            {
                sum+=i;
                int tmp=num/i;
                sum+=tmp;
            }
            if(sum>num)
                return false;
            i++;
        }
        return sum==num;
    }
};

int main()
{
    Solution s;
    s.checkPerfectNumber(6);
    return 0;
}
