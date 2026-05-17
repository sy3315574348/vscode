#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if (list1 == nullptr) return list2;
//         if (list2 == nullptr) return list1;

//         ListNode* dummy = new ListNode(-1); 
//         ListNode* cur = dummy; 

//         ListNode* p = list1;
//         ListNode* q = list2;

//         while (p != nullptr && q != nullptr) {
//             if (p->val <= q->val) {
//                 cur->next = p; 
//                 p = p->next; 
//             } else {
//                 cur->next = q;
//                 q = q->next; 
//             }
//             cur = cur->next; 
//         }

//         if (p != nullptr) {
//             cur->next = p;
//         }
//         if (q != nullptr) {
//             cur->next = q;
//         }

//         ListNode* result = dummy->next;
//         delete dummy; 
//         return result;
//     }
// };

//递归
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
        {
            return l2;
        }
        if(l2==nullptr)
        {
            return l1;
        }
        if(l1->val<l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};

int main()
{
    Solution s;
    ListNode*list1=new ListNode(1);
    list1->next=new ListNode(2);
    list1->next->next=new ListNode(4);
    ListNode*list2=new ListNode(1);
    list2->next=new ListNode(3);
    list2->next->next=new ListNode(4);
    ListNode*res=s.mergeTwoLists(list1,list2);
    while (res)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    
    return 0;
}