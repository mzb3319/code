#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int>& A,vector<int>& B,vector<int>& C,vector<int>& D)
    {
        unordered_map<int,int> table1,table2;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                table1[A[i]+B[j]]++;
                table2[C[i]+D[j]]++;
            }
        }
        int ret=0;
        for(auto itr1:table1)
        {
            auto f=table2.find(-itr1.first);
            if(f!=table2.end())
                ret+=itr1.second*f->second;
        }
        return ret;
    }
};