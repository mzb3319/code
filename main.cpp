#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len=prices.size();

        int ret=0;
        for(int i=0;i<len-1;++i)
        {
            int tmp=prices[i+1]-prices[i];
            if(tmp>0)
                ret+=tmp;
        }
        return ret;
    }
};

int main()
{
    vector<int> prices;
    Solution s;
    s.maxProfit(prices);
    return 0;
}