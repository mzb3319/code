#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int rows=0;
        while(n>rows)
        {
            rows++;
            n-=rows;
        }
        return rows;
    }
};