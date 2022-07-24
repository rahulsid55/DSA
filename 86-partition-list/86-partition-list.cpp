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
    ListNode* partition(ListNode* head, int x) {
        ListNode *t1=new ListNode(0);
        ListNode *t2=new ListNode(0);
        ListNode *x1=t1,*x2=t2;
        while(head){
            if(head->val<x){
                t1->next=new ListNode(head->val);
                t1=t1->next;
            }
            else{
                t2->next=new ListNode(head->val);
                t2=t2->next;
            }
            head=head->next;
        }
        t1->next=x2->next;
        t2->next=NULL;
        return x1->next;
        
        
    }
};