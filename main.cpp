#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string &s)
    {
        int n=s.length();
        vector<vector<int>> table(2,vector<int>(n+1,0));
        bool curr=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[j]==s[n-i-1])
                {
                    table[curr][j+1]=table[!curr][j]+1;
                }
                else
                {
                    table[curr][j+1]=max(table[!curr][j+1],table[curr][j]);
                }
            }
            curr=!curr;
        }
        return table[!curr].back();
    }
};

int main()
{
    string s="bbbab";
    Solution so;
    so.longestPalindromeSubseq(s);
    return 0;
}