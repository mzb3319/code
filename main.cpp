#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int findRadius(vector<int> &houses,vector<int>& heaters)
    {
        if(houses.size()==0||heaters.size()==0)
            return -1;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int radius=0;
        int a=0,b=0;
        int nextHeater=b;
        for(;a<houses.size();a++)
        {
            while(houses[a]>heaters[nextHeater])
            {
                b=nextHeater;
                if(nextHeater<heaters.size()-1)
                    nextHeater++;
                else
                    break;
            }
            int diff=0;
            if(houses[a]<heaters[b]&&houses[a]<heaters[nextHeater])
                diff=heaters[b]-houses[a];
            else if(houses[a]>heaters[b]&&houses[a]>heaters[nextHeater])
                diff=houses[a]-heaters[b];
            else if(houses[a]>heaters[b]&&houses[a]<heaters[nextHeater])
            {
                int diff1=houses[a]-heaters[b],diff2=heaters[nextHeater]-houses[a];
                diff=diff1<diff2?diff1:diff2;
            }
            if(radius<diff)
                radius=diff;
        }
        return radius;
    }
};