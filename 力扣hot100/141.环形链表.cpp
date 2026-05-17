#include<iostream>
#include<list>
#include<unordered_set>
using namespace std;
struct  ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// class Solution {
// public:
//     bool hasCycle(ListNode *head) 
//     {
//         unordered_set<ListNode*>node;
//         while(head!=nullptr)
//         {
//             if(node.count(head))
//                 return true;   
//             node.insert(head);
//             head=head->next;
//         }
//         return false;
//     }
// };

//快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next ==nullptr)
        {
            return false;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(slow!=fast)
        {
            if(fast==nullptr||fast->next==nullptr)
            {
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
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
    bool res=s.hasCycle(head);
    cout<<res;
    return 0;
}
