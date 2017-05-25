#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int magicalString(int n)
    {
        if(!n)
            return 0;
        int ret=1;
        vector<int> ms{1};
        vector<int> table{0,2,1};
        int index=0,preChar=1,dum=1;
        while(ms.size()<n)
        {
            if(ms[index]==dum)//change a num to add
            {
                ms.push_back(table[preChar]);
                dum=1;
                index++;
            }
            else
            {
                ms.push_back(preChar);
                dum++;
            }
            preChar=ms.back();
            if(preChar==1)
                ret++;
        }
        return ret;
    }
};