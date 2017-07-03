#include "iostream"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        unordered_map<string,bool> table;
        if(stones.size()<=1)
            return true;
        return core(stones,1,1,table);
    }

private:
    bool core(vector<int> &stones,int index,int step,unordered_map<string,bool> &table)
    {
        int Step=step+stones[index-1];
        int old_index=index-1;
        while(index<stones.size()&&stones[index]<Step)
        {
            index++;
        }
        if(index==stones.size())
            return false;

        if(stones[index]!=step+stones[old_index])
        {
            table.insert({to_string(stones[old_index])+'-'+to_string(step),false});
            return false;
        }

        if(index==stones.size()-1)
            return true;

        int step_a=step-1,step_b=step,step_c=step+1;

        string key_a,key_b,key_c;
        key_a=key_b=key_c=to_string(stones[index])+'-';

        if(step_a>0)
        {
            key_a+=to_string(step_a);
            auto f=table.find(key_a);
            if(f==table.end())
            {
                if(core(stones,index+1,step_a,table))
                    return true;
            }
            else if(f->second)
                return true;
        }
        if(step_b>0)
        {
            key_b+=to_string(step_b);
            auto f=table.find(key_b);
            if(f==table.end())
            {
                if(core(stones,index+1,step_b,table))
                    return true;
            }
            else if(f->second)
                return true;
        }
        if(step_c>0)
        {
            key_c+=to_string(step_c);
            auto f=table.find(key_c);
            if(f==table.end())
            {
                if(core(stones,index+1,step_c,table))
                    return true;
            }
            else if(f->second)
                return true;
        }
        table.insert({to_string(stones[old_index])+'-'+to_string(step),false});
        return false;
    }
};

int main()
{
    vector<int> arr{0,1,3,5,6,8,12,17};
    Solution s;
    s.canCross(arr);
    return 0;
}