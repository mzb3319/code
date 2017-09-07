#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator,int denominator)
    {
        long long n=numerator,d=denominator;
        if(n==0)
            return "0";
        bool flag=false;
        if(n<0)
        {
            flag=!flag;
            n=-n;
        }
        if(d<0)
        {
            flag=!flag;
            d=-d;
        }
        unordered_map<long long,long long> table;
        string ret;
        bool hasDot=false;
        while(true)
        {
            auto f=table.find(n);
            if(f!=table.end())
            {
                ret.insert(f->second+1,"(");
                ret.push_back(')');
                break;
            }
            if(n<d)
            {
                if(hasDot)
                    table.insert({n,ret.size()-1});
                n*=10;
                if(hasDot)
                    ret+="0";
                else
                    ret+=".";
                hasDot=true;
            }
            else
            {
                if(hasDot)
                    table.insert({n,ret.size()-1});
                ret+=to_string(n/d);
                n%=d;
                if(n)
                {
                    if(hasDot)
                        n*=10;
                }
                else
                    break;
            }
        }
        if(ret.front()=='.')
            ret="0"+ret;
        if(flag)
            ret="-"+ret;
        return ret;
    }
};
int main()
{
    Solution s;
    cout<<s.fractionToDecimal(-1,-2147483648)<<endl;
    return 0;
}