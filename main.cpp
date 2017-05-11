#include "iostream"
#include "string"

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string S;
        for(char c:s)
        {
            if(isalnum(c))
                S+=toLowercase(c);
        }
        int beg=0,end=S.size()-1;
        while(beg<=end)
        {
            if(S[beg]!=S[end])
                return false;
            beg++;
            end--;
        }
        return true;
    }
private:
    char toLowercase(char a)
    {
        if(a>='A'&&a<='Z')
            a=a-'A'+'a';
        return a;
    }
};

int main()
{
    Solution s;
    s.isPalindrome("a.");
    return 0;
}