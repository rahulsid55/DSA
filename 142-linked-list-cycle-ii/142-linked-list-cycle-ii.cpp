/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        do{
            if(slow==NULL || fast==NULL || fast->next==NULL) return NULL;
            if(slow)
            slow=slow->next;
            if(fast and fast->next)
            fast=fast->next->next;
        }
        while(slow!=fast);
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};