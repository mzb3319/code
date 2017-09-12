#include "string"
#include "vector"

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        vector<int> nums;
        vector<char> ops;
        int num=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]==' ')
                continue;
            if(isdigit(s[i]))
            {
                num=num*10+s[i]-'0';
            }
            else
            {
                ops.push_back(s[i]);
                nums.push_back(num);
                num=0;
            }
        }
        nums.push_back(num);
        if(nums.size()==1)
            return nums[0];
        vector<int> nums2;
        vector<char> ops2;
        for(int i=0,j=0;i<nums.size();++i)
        {
            num=nums[i];
            if(i==ops.size())
            {
                nums2.push_back(num);
                continue;
            }
            if(ops[i]=='+'||ops[i]=='-')
            {
                nums2.push_back(num);
                ops2.push_back(ops[i]);
            }
            else
            {
                while(ops[i]=='*'||ops[i]=='/')
                {
                    if(ops[i]=='*')
                        num*=nums[i+1];
                    else
                        num/=nums[i+1];
                    ++i;
                    if(i==ops.size())
                        break;
                }
                nums2.push_back(num);
                if(i!=ops.size())
                    ops2.push_back(ops[i]);
            }
        }
        num=nums2[0];
        for(int i=1;i<nums2.size();++i)
        {
            if(ops2[i-1]=='+')
                num+=nums2[i];
            else
                num-=nums2[i];
        }
        return num;
    }
};

int main()
{
    Solution s;
    s.calculate("3+2*2");
    return 0;
}