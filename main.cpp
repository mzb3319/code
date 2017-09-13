#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int getSum(int a,int b)
    {
        while(b!=0)
        {
            int c=a^b;
            b&=a;
            b<<=1;
            a=c;
        }
        return a;
    }
};
