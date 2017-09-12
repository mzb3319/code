#include "iostream"
#include "vector"
#include "unordered_map"
#include "cmath"

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> table{0};
        int i=1;
        while(i<=n)
        {
            int sq=sqrt(i);
            int currMin=INT32_MAX;
            for(int j=sq;j>=1;--j)
            {
                currMin=min(currMin,table[i-j*j]+1);
            }
            table.push_back(currMin);
            ++i;
        }
        return table.back();
    }
    int numSquares2(int n)
    {
        unordered_map<int,int> table;
        return core(n,table);
    }
private:
    int core(int n,unordered_map<int,int> &table)
    {
        if(n==1)
            return 1;
        auto f=table.find(n);
        if(f!=table.end())
            return f->second;
        int sq=sqrt(n);
        if(sq*sq==n)
        {
            table[n]=1;
            return 1;
        }
        int currMin=INT32_MAX;
        for(int i=sq;i>=1;--i)
        {
            currMin=min(currMin,core(n-i*i,table));
        }
        if(currMin!=INT32_MAX)
            currMin+=1;
        table[n]=currMin;
        return currMin;
    }
};

int main()
{
    Solution s;
    cout<<s.numSquares(12)<<endl;
    return 0;
}
