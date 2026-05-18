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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode*dummy=new ListNode(0);
       ListNode*node=dummy;
       int flag=0;
       while(l1||l2||flag)
       {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+flag;
            node->next=new ListNode(sum%10);
            node=node->next;
            flag=sum/10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
       }
       ListNode*res=dummy->next;
       delete dummy;
       return res;
    }
};
int main()
{
    ListNode*l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode*l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}