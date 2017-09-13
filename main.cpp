#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix,int k)
    {
        priority_queue<int> table;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix.front().size();++j)
            {
                table.push(matrix[i][j]);
                if(table.size()>k)
                    table.pop();
            }
        }
        return table.top();
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{{1,5,9},{10,11,13},{12,13,15}};
    s.kthSmallest(matrix,8);
    return 0;
}