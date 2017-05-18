#include "iostream"
#include "unordered_map"
#include "string"
#include "algorithm"
#include "vector"


using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<string> table(256);
        for(char c:s)
        {
            table[c]+=c;
        }
        string ret;
        sort(table.begin(),table.end(),[](string& a,string& b){return a.length()>b.length();});
        for(string &str:table)
        {
            if(!str.empty())
                ret+=str;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.frequencySort("1223456")<<endl;
    return 0;
}