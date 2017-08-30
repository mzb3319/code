#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1,int m,vector<int> &nums2,int n)
    {
        int index1=m-1,index2=n-1,index=m+n-1;
        while(index2>=0)
        {
            if(index1<0)
            {
                nums1[index]=nums2[index2];
                --index2;
            }
            else
            {
                if(nums1[index1]>nums2[index2])
                {
                    nums1[index]=nums1[index1];
                    --index1;
                }
                else
                {
                    nums1[index]=nums2[index2];
                    --index2;
                }
            }
            --index;
        }
    }
};
