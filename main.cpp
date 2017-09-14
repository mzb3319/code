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
    int fourSumCount(vector<int> &A,vector<int> &B,vector<int> &C,vector<int> &D)
    {
        unordered_map<int,int> AB,CD;
        for(int i=0;i<A.size();++i)
        {
            for(int j=0;j<B.size();++j)
            {
                ++AB[A[i]+B[j]];
                ++CD[-(C[i]+D[j])];
            }
        }
        int ret=0;
        for(const auto &it:AB)
        {
            auto f=CD.find(it.first);
            if(f!=CD.end())
                ret+=(it.second)*(f->second);
        }
        return ret;
    }
};
