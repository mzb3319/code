#include "iostream"
#include "string"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    string originalDigits(string &s)
    {
        unordered_map<char,int> table;
        for(char c:s)
        {
            table[c]++;
        }
        unordered_map<int,int> nums;
        nums[8]=core(table,'g');
        if(nums[8])
        {
            table['e']-=nums[8];
            table['i']-=nums[8];
            table['h']-=nums[8];
            table['t']-=nums[8];
        }
        nums[4]=core(table,'u');
        if(nums[4])
        {
            table['f']-=nums[4];
            table['o']-=nums[4];
            table['r']-=nums[4];
        }
        nums[6]=core(table,'x');
        if(nums[6])
        {
            table['s']-=nums[6];
            table['i']-=nums[6];
        }
        nums[7]=core(table,'s');
        if(nums[7])
        {
            table['e']-=2*nums[7];
            table['v']-=nums[7];
            table['n']-=nums[7];
        }
        nums[5]=core(table,'f');
        if(nums[5])
        {
            table['i']-=nums[5];
            table['v']-=nums[5];
            table['e']-=nums[5];
        }
        nums[9]=core(table,'i');
        if(nums[9])
        {
            table['n']-=2*nums[9];
            table['e']-=nums[9];
        }
        nums[3]=core(table,'h');
        if(nums[3])
        {
            table['t']-=nums[3];
            table['r']-=nums[3];
            table['e']-=2*nums[3];
        }
        nums[2]=core(table,'w');
        if(nums[2])
        {
            table['t']-=nums[2];
            table['o']-=nums[2];
        }
        nums[0]=core(table,'z');
        if(nums[0])
        {
            table['e']-=nums[0];
            table['r']-=nums[0];
            table['o']-=nums[0];
        }
        nums[1]=core(table,'o');
        if(nums[1])
        {
            table['n']-=nums[1];
            table['e']-=nums[1];
        }
        string ret;
        for(int i=0;i<10;i++)
        {
            ret+=string(nums[i],i+'0');
        }
        return ret;
    }

private:
    int core(unordered_map<char,int> &table,char c)
    {
        auto f=table.find(c);
        int ret=0;
        if(f!=table.end())
        {
            ret=f->second;
            table.erase(c);
        }
        return ret;
    }
};