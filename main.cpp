#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string two=s;
        reverse(s.begin(),s.end());
        two+="#";
        two+=s;
        vector<int> table(two.length(),0);
        for(int i=1;i<two.length();++i)
        {
            int index=i;
            while(table[index-1]!=0&&two[i]!=two[table[index-1]])
            {
                index=table[index-1];
            }
            if(two[i]==two[table[index-1]])
                table[i]=table[index-1]+1;
            else
                table[i]=table[index-1];
        }
        return s.substr(0,s.length()-table.back())+two.substr(0,s.length());
    }
};

int main()
{
    Solution s;
    string str("aacecaaa");
    cout<<s.shortestPalindrome(str)<<endl;
    return 0;
}