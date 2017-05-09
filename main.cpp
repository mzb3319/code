#include "iostream"
#include "string"
#include "deque"

using namespace std;

class Solution
{
public:
    string addBinary(string a,string b)
    {
        int len1=a.length()-1;
        int len2=b.length()-1;
        bool carry=false;
        deque<char> ret;
        while(len1>=0&&len2>=0)
        {
            char add=a[len1--]+b[len2--]-'0'-'0'+carry;
            ret.push_front(add%2+'0');
            carry=add/2;
        }
        while(len1>=0)
        {
            char add=a[len1--]+carry-'0';
            ret.push_front(add%2+'0');
            carry=add/2;
        }
        while(len2>=0)
        {
            char add=b[len2--]+carry-'0';
            ret.push_front(add%2+'0');
            carry=add/2;
        }
        if(carry)
            ret.push_front('1');
        return string(ret.begin(),ret.end());
    }
};