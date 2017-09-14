#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "algorithm"
#include "queue"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    Solution (vector<int> nums):original(nums),shuffled(nums)
    {

    }

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        for(int i=0;i<shuffled.size();++i)
        {
            int r=random()%shuffled.size();
            swap(i,r);
        }
        return shuffled;
    }
private:
    vector<int> original;
    vector<int> shuffled;
    void swap(int i,int r)
    {
        int tmp=shuffled[i];
        shuffled[i]=shuffled[r];
        shuffled[r]=tmp;
    }
};
