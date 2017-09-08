#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses,vector<pair<int,int>> &prerequisites)
    {
        unordered_map<int,vector<int>> table;
        unordered_map<int,bool> flag;
        for(auto &p:prerequisites)
        {
            table[p.second].push_back(p.first);
        }
        unordered_set<int> path;
        for(auto &p:table)
        {
            auto f=flag.find(p.first);
            if(f!=flag.end())
                continue;
            if(!core(table,p.first,path,flag))
                return false;
        }
        return true;
    }
private:
    bool core(unordered_map<int,vector<int>> &table,int course,unordered_set<int> &path,unordered_map<int,bool> &flag)
    {
        if(table.find(course)==table.end())
        {
            flag[course]=true;
            return true;
        }
        for(int i=0;i<table[course].size();++i)
        {
            if(path.find(table[course][i])!=path.end())
            {
                return false;
            }
            path.insert(table[course][i]);
            if(!core(table,table[course][i],path,flag))
                return false;
            path.erase(table[course][i]);
        }
        flag[course]=true;
        return true;
    }
};