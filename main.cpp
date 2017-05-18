#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int>& timeSeries,int duration)
    {
        int ret=0,begin=0,end=0;
        for(int time:timeSeries)
        {
            if(time>=end)
            {
                ret+=(end-begin);
                begin=time;
            }
            end=time+duration;
        }
        ret+=end-begin;
        return ret;
    }
};