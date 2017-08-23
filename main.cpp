#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int i=0,j=matrix.size()-1;
        while(i<j)
        {
            int a=i,b=j;
            while(a<j)
            {
                swap(matrix,i,a,a,j);
                swap(matrix,b,i,j,b);
                swap(matrix,i,a,j,b);
                ++a;
                --b;
            }
            ++i;
            --j;
        }
    }

private:
    void swap(vector<vector<int>> &matrix,int i,int j,int m,int n)
    {
        int tmp=matrix[i][j];
        matrix[i][j]=matrix[m][n];
        matrix[m][n]=tmp;
    }
};
