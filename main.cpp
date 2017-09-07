#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxP=INT32_MIN,posP=INT32_MIN,allP=INT32_MIN,countNeg=0,firstNeg=1,neg=1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
            {
                maxP=max(maxP,allP);
                if(countNeg>1)
                {
                    maxP=max(maxP,allP/(firstNeg));
                    if(posP==INT32_MIN)
                        posP=1;
                    maxP=max(maxP,allP/(neg*posP));
                }
                allP*=nums[i];
                maxP=max(maxP,allP);
                posP=INT32_MIN;allP=INT32_MIN;countNeg=0;firstNeg=1;neg=1;
                continue;
            }
            if(posP==INT32_MIN)
                posP=1;
            posP*=nums[i];
            if(allP==INT32_MIN)
                allP=1;
            allP*=nums[i];

            maxP=max(maxP,posP);
            if(nums[i]<0)
            {
                neg=nums[i];
                countNeg++;
                if(countNeg==1)
                    firstNeg=posP;
                posP=INT32_MIN;
            }
        }
        maxP=max(maxP,allP);
        if(countNeg>1)
        {
            maxP=max(maxP,allP/firstNeg);
            if(posP==INT32_MIN)
                posP=1;
            maxP=max(maxP,allP/(neg*posP));
        }
        return maxP;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-3,-4};
    s.maxProduct(nums);
    return 0;
}
