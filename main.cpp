#include "iostream"
#include "vector"
#include "deque"

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry=1;
        deque<int> ret;
        for(int i=digits.size()-1;i>=0;--i)
        {
            int tmp=digits[i]+carry;
            ret.push_front(tmp%10);
            carry=tmp/10;
        }
        if(carry!=0)
            ret.push_front(carry);
        return vector<int>(ret.begin(),ret.end());
    }
};
