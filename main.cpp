#include "iostream"
#include "vector"
#include "random"

using namespace std;

class Solution
{
public:
    Solution(vector<int> nums)
    {
        origin=shuffleNums=nums;
        e.seed(time(0));
        uniform_int_distribution<unsigned>::param_type param{0,nums.size()-1};
        u.param(param);
    }
    vector<int> reset()
    {
        shuffleNums=origin;
        return shuffleNums;
    }
    vector<int> shuffle()
    {
        for(int i=0;i<shuffleNums.size();i++)
        {
            int swap=u(e);
            int tmp=shuffleNums[i];
            shuffleNums[i]=shuffleNums[swap];
            shuffleNums[swap]=tmp;
        }
        return shuffleNums;
    }
private:
    vector<int> origin,shuffleNums;
    uniform_int_distribution<unsigned> u;
    default_random_engine e;
};