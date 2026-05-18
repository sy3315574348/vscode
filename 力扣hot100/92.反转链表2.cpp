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
    /*void reverseLinkedList(ListNode *head) {
        ListNode*pre=nullptr;
        ListNode*cur=head;
        while(cur!=nullptr)
        {
            ListNode*next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;

        ListNode*pre=dummy;
        //找前驱，要拼接的地方的左侧
        for(int i=0;i<left-1;i++)
        {
            pre=pre->next;
        }
        //找结束
        ListNode*rightnode=pre;
        for(int i=0;i<right-left+1;i++)
        {
            rightnode=rightnode->next;
        }

        ListNode*leftnode=pre->next;
        ListNode*cur=rightnode->next;//存一下一会要拼接的地方的右侧    
        //先断开
        pre->next=nullptr;
        rightnode->next=nullptr;

        //反转
        reverseLinkedList(leftnode);

        //拼接
        pre->next=rightnode;
        leftnode->next=cur;
        ListNode*res=dummy->next;
        delete dummy;
        return res;
        
    }*/

        ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*pre=dummy;
        //先找到前驱
        for(int i=0;i<left-1;i++)
        {
            pre=pre->next;
        }
        ListNode*cur=pre->next;
        
        for(int i=0;i<right-left;i++)
        {
            ListNode*next=cur->next;
            cur->next=next->next;
            next->next=pre->next;
            pre->next=next;
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
    ListNode* result = solution.reverseBetween(head, 2, 4);

    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}