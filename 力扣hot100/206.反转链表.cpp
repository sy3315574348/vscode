#include<iostream>
#include<list>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*cur=head,*pre=nullptr;
        while(cur!=nullptr)
        {
            ListNode*tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};
int main()
{
    Solution s;
    ListNode*head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    ListNode*res=s.reverseList(head);
    while(res!=nullptr)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}