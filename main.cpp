#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        vector<string> ret{"1",""};
        bool flag=true;
        while(n>1)
        {
            ret[flag].clear();
            int count=1;
            char c=ret[!flag][0];
            for(int i=1;i<ret[!flag].size();++i)
            {
                if(ret[!flag][i]==c)
                    ++count;
                else
                {
                    ret[flag]+=to_string(count)+c;
                    c=ret[!flag][i];
                    count=1;
                }
            }
            ret[flag]+=to_string(count)+c;
            flag=!flag;
            --n;
        }
        return ret[!flag];
    }
};


int main()
{
    Solution s;
    cout<<s.countAndSay(5)<<endl;
    return 0;
}