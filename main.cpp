#include "iostream"
#include "vector"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int a):val(a),next(nullptr){}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if(head== nullptr)
            return head;
        int len=0;
        ListNode *p=head;
        while(p)
        {
            ++len;
            p=p->next;
        }
        return core(head,len);
    }
private:
    ListNode *core(ListNode *head,int len)
    {
        if(len==1)
            return head;
        int mid=len/2;
        ListNode *right=head,*left=head,*pre= nullptr;
        for(int i=0;i<mid;++i)
        {
            pre=right;
            right=right->next;
        }
        pre->next= nullptr;
        //sort left
        left=core(left,len/2);
        //sort right
        right=core(right,len/2+len%2);

        return merge(left,right);
    }
    ListNode *merge(ListNode *left,ListNode *right)
    {
        ListNode head(-1),*p=&head;
        while(left!= nullptr||right!= nullptr)
        {
            if(left== nullptr)
            {
                p->next=right;
                break;
            }
            else if(right== nullptr)
            {
                p->next=left;
                break;
            }

            if(left->val>right->val)
            {
                p->next=right;
                p=p->next;
                right=right->next;
            }
            else
            {
                p->next=left;
                p=p->next;
                left=left->next;
            }
        }
        return head.next;
    }
};

int main()
{
    vector<int> num{1,23,2,4,2};
    ListNode head(-1),*p=&head;
    for(int i=0;i<num.size();++i)
    {
        p->next=new ListNode(num[i]);
        p=p->next;
    }
    Solution s;
    s.sortList(head.next);
    return 0;
}
