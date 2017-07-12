#include "iostream"
#include "vector"
#include "unordered_set"
#include "deque"
#include "algorithm"

using namespace std;

//这个题直接看答案，标准答案上的第三种方法，计算空闲槽的方法，可以归结到数学上。
class Solution
{
public:
    int leastInterval(vector<char> &tasks,int n)
    {
        unordered_set<char> table;
        deque<char> tasksQ;
        vector<pair<char,int>> tArr(26,pair<char,int>{'a',0});
        for(char c:tasks)
        {
            tArr[c-'A'].first=c;
            tArr[c-'A'].second++;
        }
        sort(tArr.begin(),tArr.end(),[](pair<char,int> &a,pair<char,int> &b){return a.second>b.second;});
        int ret=0;
        int N=tasks.size();
        while(N)
        {
            ret++;
            char nt=findNextTask(tArr,table,n);
            tasksQ.push_back(nt);
            if(tasksQ.size()>n)
            {
                char p=tasksQ.front();
                if(isalpha(p))
                {
                    table.erase(p);
                }
                tasksQ.pop_front();
            }
            if(nt)
            {
                N--;
            }
        }
        return ret;
    }
private:
    char findNextTask(vector<pair<char,int>> &arr,unordered_set<char> &table,int n)
    {
        int index=0;
        sort(arr.begin(),arr.end(),[](pair<char,int> &a,pair<char,int> &b){return a.second>b.second;});
        int i=26;
        while(i)
        {
            i--;
            if(index>25)
                index=0;
            if(arr[index].second==0)
            {
                index++;
                continue;
            }
            char fc=arr[index].first;
            auto f=table.find(fc);
            if(f==table.end())
            {
                table.insert(fc);
                arr[index++].second--;
                return fc;
            }
            index++;
        }
        return 0;
    }
};

int main()
{
    vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'};
    Solution s;
    s.leastInterval(tasks,2);
    return 0;
}