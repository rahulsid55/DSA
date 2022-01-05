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
    ListNode *reverse(ListNode *head ){
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        ListNode *shead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return shead;
    }
    ListNode *sum(ListNode* l1, ListNode* l2){
        int carry=0;
        ListNode *temp=new ListNode(0);
        ListNode *dummy=temp;
        
        while(l1 || l2 || carry){
            int ans=0;
            if(l1){
                ans+=l1->val;
                l1=l1->next;
            }
            if(l2){
                ans+=l2->val;
                l2=l2->next;
            }
            if(carry)
            {
                ans+=carry;
            }
            carry=ans/10;
            ListNode *x=new ListNode(ans%10);
            temp->next=x;
            temp=temp->next;
        }
        temp->next=NULL;
        return dummy->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode *ans=sum(l1,l2);
        return reverse(ans);
    }
};