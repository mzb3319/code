#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins,int amount)
    {
        //unordered_map<int,int> table;
        vector<int> table(amount+1,-2);
        int ret=core(coins,amount,table);
        return ret==INT32_MAX?-1:ret;
    }
private:
    int core(vector<int> &coins,int amount,vector<int> &table)
    {
        if(amount<0)
            return INT32_MAX;
        if(amount==0)
            return 0;
        if(table[amount]!=-2)
            return table[amount];
        int need=INT32_MAX;
        for(int i=0;i<coins.size();++i)
            need=min(need,core(coins,amount-coins[i],table));
        if(need!=INT32_MAX)
            need+=1;
        table[amount]=need;
        return need;
    }
};

int main()
{
    Solution s;
    vector<int> coins{1,2,5};
    s.coinChange(coins,11);
    return 0;
}
