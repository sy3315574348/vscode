#include<iostream>
#include<list>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode*p=headA;
//         ListNode*q=headB;
//         while(p!=q)
//         {
//             p=p?p->next:headB;
//             q=q?q->next:headA;
//         }
//         return p;
//     }
// };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (visited.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};


int main()
{
    Solution s;
    ListNode*headA=new ListNode(4);
    headA->next=new ListNode(1);
    ListNode*headB=new ListNode(5);
    headB->next=new ListNode(0);
    headB->next->next=new ListNode(1);
    headA->next->next=new ListNode(8);
    headA->next->next->next=new ListNode(4);
    headA->next->next->next->next=new ListNode(5);
    headB->next->next->next=headA->next->next;
    ListNode*res=s.getIntersectionNode(headA,headB);
    if(res)
        cout<<res->val;
    else
        cout<<"null";
    return 0;
}