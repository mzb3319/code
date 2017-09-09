#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

struct course
{
    int num;
    int color;
    int order;
    course(int n):num(n),color(0),order(0){}
};

class Solution
{
public:
    vector<int> findOrder(int numCourses,vector<pair<int,int>> &prerequisites)
    {
        vector<int> courses(numCourses,0);
        vector<bool> visited(numCourses,false);
        unordered_map<int,vector<int>> table;
        unordered_set<int> path;
        for(auto &it:prerequisites)
            table[it.first].push_back(it.second);
        int n=0;
        for(int i=0;i<numCourses;++i)
        {
            if(visited[i])
                continue;
            if(!core(courses,visited,table,i,n,path))
                return {};
        }
        vector<int> ret(numCourses);
        for(int i=0;i<numCourses;++i)
        {
            ret[courses[i]]=i;
        }
        return ret;
    }
private:
    bool core(vector<int> &courses,vector<bool> &visited,unordered_map<int,vector<int>> &table,int course,int &n,unordered_set<int> &path)
    {
        if(path.find(course)!=path.end())
            return false;
        if(visited[course])
            return true;
        visited[course]=true;
        path.insert(course);
        for(auto &it:table[course])
        {
            if(!core(courses,visited,table,it,n,path))
                return false;
        }
        path.erase(course);
        courses[course]=n;
        ++n;
        return true;
    }
};

int main()
{
    vector<pair<int,int>> prere{{1,0}};
    Solution s;
    s.findOrder(2,prere);
    return 0;
}