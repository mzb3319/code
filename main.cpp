#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if(heights.empty())
            return 0;
        vector<int> left2right(heights.size(),0),right2left(heights.size(),0);
        left2right[0]=-1;
        right2left[heights.size()-1]=heights.size();
        /*
         * 找到左边和右边第一个小于当前值的位置,如果某一点a的值大于当前值,那么如果点a左边第一个小于a的值
         * 都大于或等于当前值,则继续比较a点左边的值,a点右边的值肯定都大于或等于当前值
         */
        for(int i=1;i<heights.size();++i)
        {
            int p=i-1;
            while(p>=0&&heights[p]>=heights[i])
                p=left2right[p];
            left2right[i]=p;
        }
        for(int i=heights.size()-2;i>=0;--i)
        {
            int p=i+1;
            while(p<heights.size()&&heights[p]>=heights[i])
                p=right2left[p];
            right2left[i]=p;
        }
        int maxArea=INT32_MIN;
        for(int i=0;i<heights.size();++i)
        {
            maxArea=max(maxArea,heights[i]*(right2left[i]-left2right[i]-1));
        }
        return maxArea;
    }
};

int main()
{
    vector<int> heights{1,1};
    Solution s;
    s.largestRectangleArea(heights);
    return 0;
}
