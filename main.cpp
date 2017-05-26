#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool PredictTheWinner(vector<int>& nums)
    {
        int table[20][20];
        int all=0;
        for(int i=0;i<nums.size();i++)
        {
            table[i][i]=nums[i];
            all+=nums[i];
        }
        for(int i=2;i<=nums.size();i++)
        {
            for(int j=0;j<=nums.size()-i;j++)
            {
                int end=j+i-1;
                int add=0;
                for(int k=j;k<=end;k++)
                    add+=nums[k];
                int m=min(table[j+1][end],table[j][end-1]);
                table[j][end]=add-m;
            }
        }
        if(table[0][nums.size()-1]>=(all/2+all%2))
            return true;
        return false;
    }
};