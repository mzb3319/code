#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len=prices.size();
        for(int i=0;i<len-1;++i)
            prices[i]=prices[i+1]-prices[i];

        int m=0,add=0;
        for(int i=0;i<len-1;++i)
        {
            add+=prices[i];
            m=max(m,add);
            add=max(add,0);
        }
        return m;
    }
};

int main()
{
    vector<int> prices;
    Solution s;
    s.maxProfit(prices);
    return 0;
}