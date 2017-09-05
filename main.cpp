#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string &s)
    {
        vector<vector<string>> ret;
        vector<string> tmp;
        core(s,0,tmp,ret);
        return ret;
    }
private:
    void core(string &s,int index,vector<string> &tmp,vector<vector<string>> &ret)
    {
        if(index==s.length())
        {
            ret.push_back(tmp);
            return;
        }
        for(int i=index;i<s.length();++i)
        {
            int l=index,r=i;
            while(l<=r&&s[l]==s[r])
            {
                l++;
                --r;
            }
            if(l>r)
            {
                tmp.push_back(s.substr(index,i-index+1));
                core(s,i+1,tmp,ret);
                tmp.pop_back();
            }
        }
    }
};
int main()
{
    unsigned  char a=0x80;
    unsigned char b=a>>5;
    cout<<(int)b<<endl;
    return 0;
}