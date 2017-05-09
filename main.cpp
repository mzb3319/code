#include "iostream"
#include "string"
#include "sstream"

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string& s)
    {
        string str;
        istringstream sin(s);
        while(sin>>str);
        return str.length();
    }
};