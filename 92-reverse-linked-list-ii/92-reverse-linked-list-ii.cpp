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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *t1=head,*t2=head;
        int c1=1,c2=1;
        while(t1 and c1!=left){
            t1=t1->next;
            c1++;
        }
        while(t2 and c2!=right){
            t2=t2->next;
            c2++;
        }
        if(t1==t2){
            return head;
        }
        //cout<<t2->val;
        ListNode *x1=head;
        while(x1 and x1!=t1 and x1->next!=t1){
            x1=x1->next;
        }
        ListNode *prev=NULL,*x2=t2->next,*x3=t1;
        while(t1 and t1!=x2){
            ListNode *temp=t1->next;
            t1->next=prev;
            prev=t1;
            t1=temp;
        }
        if(x1==x3){
            head=prev;
            cout<<1;
        }
        else{
            x1->next=prev;
        }
        x3->next=x2;
        
        
        return head;
        
        
        
        
    }
};