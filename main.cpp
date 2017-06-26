#include "iostream"
#include "string"
#include "deque"

using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string s,int K)
    {
        deque<char> str;
        int count=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='-')
                continue;
            str.push_front(toupper(s[i]));
            count++;
            if(count==K)
            {
                count=0;
                str.push_front('-');
            }
        }
        if(str.front()=='-')
            str.pop_front();
        string ret(str.begin(),str.end());
        return ret;
    }
};