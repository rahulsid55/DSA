/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int ans;
       ListNode *dummy=new ListNode();
        ListNode *temp=dummy;
       int carry=0;
        while(l1 || l2 || carry)
        {
            ans=0;
            if(l1)
            {
                ans+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                ans+=l2->val;
                l2=l2->next;
            }
            if(carry)
            {
                ans+=carry;
            }
            carry=ans/10;
            ListNode *node=new ListNode(ans%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};