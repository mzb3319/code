#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    int shoppingOffers(vector<int> &price,vector<vector<int>> &special,vector<int> &needs)
    {
        unordered_map<string,int> table;
        return core(price,special,0,needs,table);
    }
private:
    int core(vector<int> &price,vector<vector<int>> &special,int index,vector<int> needs,unordered_map<string,int> &table)
    {
        if(index>=special.size())
            return buyOne(price,needs);
        string s;
        for(int n:needs)
            s+=to_string(n)+",";
        auto f=table.find(s);
        if(f!=table.end())
            return f->second;

        int min=INT32_MAX;
        int curr=0;
        int i=0;
        for(;i<7&&check(special[index],needs);++i)
        {
            curr=i*special[index].back();
            if(i)
                buy(special[index],needs);
            curr+=core(price,special,index+1,needs,table);

            if(curr<min)
                min=curr;
        }
        if(!i)
        {
            curr=core(price,special,index+1,needs,table);
            if(curr<min)
                min=curr;
        }
        table.insert({s,min});
        return min;
    }
    bool check(const vector<int> &special,const vector<int> &needs)
    {
        for(int i=0;i<needs.size();++i)
            if(needs[i]<special[i])return false;
        return true;
    }
    void buy(const vector<int> &special,vector<int> &needs)
    {
        for(int i=0;i<needs.size();++i)
            needs[i]-=special[i];
    }
    int buyOne(const vector<int> &price,const vector<int> &needs)
    {
        int ret=0;
        for(int i=0;i<needs.size();++i)
            if(needs[i]>0)ret+=needs[i]*price[i];
        return ret;
    }
};

int main()
{
    vector<int> price{2,5},needs{3,2};
    vector<vector<int>> special{{3,0,5},{1,2,10}};
    Solution s;
    cout<<s.shoppingOffers(price,special,needs)<<endl;
    return 0;
}