#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "deque"

using namespace std;

class Solution
{
public:
    string minWindow(string &s,string &t)
    {
        if(t.empty()||t.length()>s.length())
            return "";
        int count=t.size();
        unordered_map<char,int> table;
        for(char c:t)
            ++table[c];
        int minWin=INT32_MAX,index=0;
        deque<int> pos;
        for(int i=0;i<s.length();++i)
        {
            if(table.find(s[i])==table.end())
                continue;
            if(!pos.empty()&&table[s[i]]<=0&&s[pos.front()]==s[i])
            {
                pos.pop_front();
                pos.push_back(i);
            }
            else
            {
                if(table[s[i]]>0)
                    count--;
                --table[s[i]];
                pos.push_back(i);
            }

            if(count==0)
            {
                int tmp=i-pos.front()+1;
                if(minWin>tmp)
                {
                    minWin=tmp;
                    index=pos.front();
                }
                ++count;
                ++table[s[pos.front()]];
                pos.pop_front();

            }
            while(!pos.empty()&&(table[s[pos.front()]]<0))
            {
                ++table[s[pos.front()]];
                pos.pop_front();
            }
        }
        if(minWin==INT32_MAX)
            return "";
        return s.substr(index,minWin);
    }
};

int main()
{
    string s="acbbaca",t="aba";
    Solution ss;
    cout<<ss.minWindow(s,t)<<endl;
    return 0;
}
