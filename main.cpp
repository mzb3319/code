#include "vector"
#include "iostream"
#include "unordered_set"
#include "bitset"
#include "deque"

using namespace std;

class Solution
{
public:
    int ladderLength(string &beginWord,string &endWord,vector<string> &wordList)
    {
        unordered_set<string> table(wordList.begin(),wordList.end());
        if(table.find(endWord)==table.end())
            return 0;
        deque<string> q{beginWord};
        int ret=0,currCount=1,nextCount=0;
        while(!q.empty())
        {
            if(q.front()==endWord)
                return ret+1;
            int count=getNext(q.front(),table,q);
            nextCount+=count;
            --currCount;
            q.pop_front();
            if(currCount==0)
            {
                ++ret;
                currCount=nextCount;
                nextCount=0;
            }
        }
        return 0;
    }
private:
    int getNext(string a,unordered_set<string> &table,deque<string> &q)
    {
        int count=0;
        for(int i=0;i<a.size();++i)
        {
            for(int j=0;j<26;++j)
            {
                char c=a[i];
                if(c-'a'!=j)
                {
                    a[i]=j+'a';
                    if(table.find(a)!=table.end())
                    {
                        q.push_back(a);
                        ++count;
                        table.erase(a);
                    }
                    a[i]=c;
                }
            }
        }
        return count;
    }
};

int main()
{
    string bw="leet",ew="code";
    vector<string> wl{"lest","leet","lose","code","lode","robe","lost"};
    Solution s;
    cout<<s.ladderLength(bw,ew,wl);
    return 0;
}
