#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    int strStr(string &haystack,string &needle)
    {
        if(haystack.empty()||haystack.length()<needle.length())
            return -1;
        for(int i=0;i<haystack.length()-needle.length()+1;++i)
        {
            int index1=i,index2=0;
            while(haystack[index1]==needle[index2])
            {
                ++index1;++index2;
            }
            if(index2==needle.length())
                return i;
        }
        return -1;
    }
};