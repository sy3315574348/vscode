#include<iostream>
#include<list>
#include<unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deteCycle(ListNode *head) {
        if(head==nullptr||head->next ==nullptr)
        {
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;
        while (slow!=fast)
        {
            if(fast==nullptr||fast->next==nullptr)
            {
                return nullptr;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->next;
    }
};
int main()
{
    Solution s;
    ListNode*head=new ListNode(3);
    head->next=new ListNode(2);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(-4);
    head->next->next->next->next=head->next;
    ListNode*res=s.deteCycle(head);
    if(res)
        cout<<res->val;
    else
        cout<<"no cycle";
    return 0;
}