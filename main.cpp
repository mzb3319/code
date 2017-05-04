#include "iostream"
#include "string"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> table{'a','e','i','o','u','A','E','I','O','U'};
        int beg=0,end=s.length()-1;
        while(beg<=end)
        {
            if(table.find(s[beg])!=table.end()&&table.find(s[end])!=table.end())
            {
                char tmp=s[beg];
                s[beg]=s[end];
                s[end]=tmp;
                beg++;
                end--;
            }
            else if(table.find(s[beg])==table.end())
                beg++;
            else
                end--;
        }
        return s;
    }
};