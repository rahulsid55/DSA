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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *temp=head;
        ListNode *temp1=head;
        ListNode *t2=temp;
        int c=0;
        while(t2)
        {
            t2=t2->next;
            c++;
        }
        k=k%c;
        while(k--)
        {
            temp=temp->next;
        }
        while(temp->next)
        {
            temp1=temp1->next;
            temp=temp->next;
        }
        temp->next=head;
        head=temp1->next;
        temp1->next=NULL;
        return head;
            
        
    }
};