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
    ListNode* swapNodes(ListNode* head, int k) {
        int t=k-1;
        ListNode *t1=head,*t2=head,*t3;
        while(t){
            t1=t1->next;
            t--;
        }
        t3=t1;
        while(t1->next!=NULL){
            t1=t1->next;
            t2=t2->next;
        }
        swap(t3->val,t2->val);
        return head;
        
        
    }
};