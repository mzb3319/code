#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    Solution(vector<int> nums)
    {
        NUM=nums;
    }

    int pick(int target)
    {
        int ret=-1;
        int count=0;
        for(int i=0;i<NUM.size();i++)
        {
            if(NUM[i]!=target)
                continue;
            if(!count)
            {
                count++;
                ret=i;
            }
            else
            {
                if(rand()%count==0)
                    ret=i;
            }
        }
        return ret;
    }
private:
    vector<int> NUM;
};
