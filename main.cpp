#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> table{n};
        while(true)
        {
            int tmp=0;
            while(n)
            {
                int m=n%10;
                tmp+=m*m;
                n/=10;
            }
            if(tmp==1)
                return true;
            auto f=table.find(tmp);
            if(f!=table.end())
                return false;
            n=tmp;
            table.insert(tmp);
        }
        return false;
    }
};