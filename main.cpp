#include "iostream"
#include "string"

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        return core(s,0,s.length()-1);
    }

private:
    string core(string &s,int b,int e)
    {
        string num;
        string text;
        string ret;
        for(int i=b;i<=e;i++)
        {
            if(isdigit(s[i]))
            {
                num+=s[i];
            }
            else if(isalpha(s[i]))
            {
                text+=s[i];
            }
            else if(s[i]=='[')
            {
                int beg=i+1;
                int count=1;
                while(i<=e)
                {
                    i++;
                    if(s[i]=='[')
                        count++;
                    else if(s[i]==']')
                        count--;
                    if(!count)
                        break;
                }
                string r=core(s,beg,i-1);
                int n=stoi(num);
                ret+=text;
                text.clear();
                while(n--)
                {
                    ret+=r;
                }
                num.clear();
            }
        }
        ret+=text;
        return ret;
    }
};

int main()
{
    string str("sd2[f2[e]g]i");
    Solution so;
    so.decodeString(str);
    return 0;
}