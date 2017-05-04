#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        if(digits.size()==0)
            return {};
        digits.back()+=1;
        bool carry=false;
        for(int i=digits.size()-1;i>=0;i--)
        {
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=9;
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;
    }
};