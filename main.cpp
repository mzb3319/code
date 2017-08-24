#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len=prices.size();

        vector<int> l2r{0},r2l{0};
        int currMax=0;
        for(int i=0;i<len-1;++i)
        {
            currMax+=prices[i+1]-prices[i];
            int tmp=currMax>l2r.back()?currMax:l2r.back();
            l2r.push_back(tmp);
            currMax=max(currMax,0);
        }
        int currMin=0;
        for(int i=len-1;i>0;--i)
        {
            currMin+=prices[i-1]-prices[i];
            int tmp=currMin<r2l.back()?currMin:r2l.back();
            if(tmp<0)
                tmp=-tmp;
            r2l.push_back(tmp);
            currMin=min(currMin,0);
        }
        len=l2r.size();
        int ret=0;
        for(int i=0;i<l2r.size();++i)
        {
            int a=l2r[i],b=r2l[len-i-1];
            int c=a+b;
            ret=max(ret,c);
            ret=max(ret,max(a,b));
        }
        return ret;
    }
    //假设手中最开始有0元,对每天的价格,维护一个到目前为止的最低价来购买,售出则看当前已经可以售出的最高价和当前售出价格(当天价格减去维护的最低价)哪个大;
    //第二次购买是在假设已经买卖一次,那么手中的钱就要从第一次买卖的最高价开始算
    int maxProfit1(vector<int> &prices)
    {
        int buy1=INT32_MIN,buy2=INT32_MIN,sel1=0,sel2=0;

        for(int i=0;i<prices.size();++i)
        {
            buy1=max(buy1,0-prices[i]);
            sel1=max(sel1,prices[i]+buy1);
            buy2=max(buy2,sel1-prices[i]);
            sel2=max(sel2,prices[i]+buy2);
        }
        return max(sel1,sel2);
    }
};

int main()
{
    vector<int> prices;
    Solution s;
    s.maxProfit(prices);
    return 0;
}