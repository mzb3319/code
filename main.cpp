#include "iostream"
#include "string"
#include "vector"

using namespace std;


class Solution
{
public:
    int numDecodings(string &s)
    {
        const int M=1000000007;
        vector<unsigned long long> table(s.length(),0);
        for(int i=s.length()-1;i>=0;--i)
        {
            int pIndex=i+1,ppIndex=i+2;
            char c=s[i];
            if(c=='0')
            {
                if(pIndex<s.length()&&s[pIndex]=='0')
                    return 0;
                continue;
            }
            if(c=='*')
            {
                if(pIndex>=s.length())
                {
                    table[i]=9;
                }
                else
                {
                    if(s[pIndex]=='0')
                    {
                        if(ppIndex<s.length()&&s[ppIndex]!='0')
                            table[i]=2*table[ppIndex];
                        else
                            table[i]=2;
                    }
                    else
                    {
                        if(ppIndex<s.length()&&s[ppIndex]=='0')
                        {
                            table[i]=9*table[pIndex];
                        }
                        else
                        {
                            table[i]=9*table[pIndex];
                            unsigned long long add=1;
                            if(ppIndex<s.length())
                                add=table[ppIndex];
                            if(s[pIndex]=='*')
                            {
                                table[i]+=15*add;
                            }
                            else
                            {
                                if(s[pIndex]<'7')
                                {
                                    table[i]+=2*add;
                                }
                                else
                                {
                                    table[i]+=add;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if(pIndex>=s.length())
                {
                    if(s[i]=='0')
                        table[i]=0;
                    else
                        table[i]=1;
                }
                else
                {
                    if(s[pIndex]=='0')
                    {
                        if(s[i]>='3')
                            return 0;
                        if(ppIndex<s.length()&&s[ppIndex]!='0')
                        {
                            table[i]=table[ppIndex];
                        }
                        else
                            table[i]=1;
                    }
                    else
                    {
                        if(ppIndex<s.length()&&s[ppIndex]=='0')
                        {
                            table[i]=table[pIndex];
                        }
                        else
                        {
                            table[i]=table[pIndex];
                            unsigned long long add=1;
                            if(ppIndex<s.length())
                                add=table[ppIndex];
                            if(s[pIndex]=='*')
                            {
                                if(s[i]<'3')
                                {
                                    if(s[i]=='1')
                                        table[i]+=9*add;
                                    else
                                        table[i]+=6*add;
                                }
                            }
                            else
                            {
                                string str{s[i],s[pIndex]};
                                int num=stoi(str);
                                if(num<=26)
                                    table[i]+=add;
                            }
                        }
                    }
                }
            }
            table[i]=table[i]%M;
        }
        return (int)table[0];
    }
};


int main()
{
    Solution s;
    string str("**");
    cout<<s.numDecodings(str)<<endl;
    return 0;
}