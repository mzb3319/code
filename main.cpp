#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int maxProfit(int k,vector<int> &prices)
    {
        //这种情况就表示买卖次数超过一般后,我们可以一次买,接着卖,只要是赚钱的就可以买卖操作
        if(k>prices.size()/2)
        {
            int ret=0;
            for(int i=1;i<prices.size();++i)
            {
                ret+=max(prices[i]-prices[i-1],0);
            }
            return ret;
        }
        vector<int> buy(k+1,INT32_MIN),sel(k+1,0);
        int ret=0;
        for(int i=0;i<prices.size();++i)
        {
            for(int j=1;j<=k;++j)
            {
                buy[j]=max(buy[j],sel[j-1]-prices[i]);
                sel[j]=max(sel[j],prices[i]+buy[j]);
                if(sel[j]>ret)
                    ret=sel[j];
            }
        }
        return ret;
    }
};

int main()
{
    cout<<INT32_MAX<<endl;
    return 0;
}