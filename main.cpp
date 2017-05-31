#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution
{
public:
    int minDistance(string &word1,string &word2)
    {
        int len1=word1.length(),len2=word2.length();
        vector<vector<int>> table(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                    table[i][j]=table[i-1][j-1]+1;
                else if(table[i-1][j]>table[i][j-1])
                    table[i][j]=table[i-1][j];
                else
                    table[i][j]=table[i][j-1];
            }
        }
        return len1+len2-2*table[len1][len2];
    }
};

int main()
{
    string a="sea",b="eat";
    Solution s;
    s.minDistance(a,b);
    return 0;
}