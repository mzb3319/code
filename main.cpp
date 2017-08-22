#include "istream"
#include "vector"

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left_max=0,right_max=0;
        int beg=0,end=height.size()-1;
        int ret=0;
        while(beg<end)
        {
            if(height[beg]<=height[end])
            {
                if(left_max<height[beg])
                    left_max=height[beg];
                ++beg;
                int tmp=left_max-height[beg];
                if(tmp>0)
                    ret+=tmp;
            }
            else
            {
                if(right_max<height[end])
                    right_max=height[end];
                --end;
                int tmp=right_max-height[end];
                if(tmp>0)
                    ret+=tmp;
            }
        }
        return ret;
    }
};