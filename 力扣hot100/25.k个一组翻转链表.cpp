#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*groupPre=dummy;
        while(true)
        {
            //找头
            ListNode*cur=groupPre;
            //找尾
            int kk=k;
            while(kk>0&&cur)
            {
                kk--;
                cur=cur->next;
            }
            if(!cur)
            {
                break;
            }
            ListNode*groupNext=cur->next;
            ListNode*pre=groupNext;
            cur=groupPre->next;
            ListNode*tmp=NULL;
            while(cur!=groupNext)
            {
                tmp=cur->next;
                cur->next=pre;
                pre=cur;
                cur=tmp;
            }
            tmp=groupPre->next;
            groupPre->next=pre;
            groupPre=tmp;
        }
        return dummy->next;
    }
};
int main()
{
    ListNode*head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    Solution solution;
    int k=2;
    ListNode*result=solution.reverseKGroup(head,k);
    while(result)
    {
        cout<<result->val<<" ";
        result=result->next;
    }
    return 0;
}