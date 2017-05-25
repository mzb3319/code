#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> table{0,1};
        for(int i=2;i<=n;i++)
        {
            int tmp=INT32_MIN;
            for(int k=1;k<i;k++)
            {
                int t=k*table[i-k];
                if(t>tmp)
                    tmp=t;
            }
            if(i!=n&&tmp<i)
                tmp=i;
            table.push_back(tmp);
        }
        return table.back();
    }
};

int main()
{
    Solution s;
    cout<<s.integerBreak(2)<<endl;
    return 0;
}