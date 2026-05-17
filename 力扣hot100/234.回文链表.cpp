#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
//复制一份成数组，双指针真前后对比
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int>vals;
//         while(head!=nullptr)
//         {
//             vals.push_back(head->val);
//             head=head->next;
//         }
//         for(int i=0,j=(int)vals.size()-1;i<j;i++,j--)
//         {
//             if(vals[i]!=vals[j])
//                 return false;
//         }
//         return true;
//     }
// };


// //递归
// class Solution {
// public:
//     ListNode*frontpoint;
//     bool isPalindrome(ListNode* head) {
//         frontpoint=head;
//         return recursivelyCheck(head);
//     }
//     bool recursivelyCheck(ListNode* cur)
//     {
//         if(cur!=nullptr)
//         {
//             if(!recursivelyCheck(cur->next))
//                 return false;
//             if(cur->val!=frontpoint->val)
//                 return false;
//             frontpoint=frontpoint->next;
//         }
//         return true;
//     }
// };

//快慢指针
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr)
            return true;
        ListNode*slow=head,*fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=nullptr)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
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
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(1);
    bool res=s.isPalindrome(head);
    cout<<res;
    return 0;
}