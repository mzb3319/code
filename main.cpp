#include "iostream"
#include "string"
#include "unordered_map"
#include "sstream"

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern,string str)
    {
        unordered_map<char,string> pattern2str;
        unordered_map<string,char> str2pattern;
        istringstream s(str);
        string word;
        int i=0;
        while(s>>word)
        {
            if(i>=pattern.length())
                return false;
            auto fp=pattern2str.find(pattern[i]);
            auto fs=str2pattern.find(word);
            if(fp==pattern2str.end()&&fs==str2pattern.end())
            {
                pattern2str[pattern[i]]=word;
                str2pattern[word]=pattern[i];
            }
            else if(fp!=pattern2str.end()&&fp->second==word&&fs!=str2pattern.end()&&fs->second==pattern[i])
            {
                ;
            }
            else
                return false;
            i++;
        }
        return i==pattern.length();
    }
};