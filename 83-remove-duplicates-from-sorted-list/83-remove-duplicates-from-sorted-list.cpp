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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode *t1=head->next,*t2=head;
        while(t1){
            if(t1->val==t2->val){
                t1=t1->next;
            }
            else{
                t2->next=t1;
                t2=t1;
                t1=t1->next;
            }
        }
        t2->next=t1;
        return head;
        
        
    }
};