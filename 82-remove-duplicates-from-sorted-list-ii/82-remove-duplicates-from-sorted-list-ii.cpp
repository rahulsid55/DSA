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
        int count[201]={0};
        while(head!=NULL){
            count[head->val+100]+=1;
            head=head->next;
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        for(int i=1;i<201;i++){
            if(count[i]==1){
                ListNode *x=new ListNode(i-100);
                dummy->next=x;
                dummy=dummy->next;
            }
        }
        dummy->next=NULL;
        return temp->next;
    }
};