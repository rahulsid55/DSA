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
    int len(ListNode *head)
    {
        int c=0;
        while(head)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode *reverse(ListNode *head){
        if(head==NULL or head->next==NULL)
            return head;
        ListNode *shead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return shead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=len(l1);
        int len2=len(l2);
        if(len(l1)<len(l2)){
            return addTwoNumbers(l2,l1);
        }
        stack<int> s;
        int diff=len1-len2;
        //cout<<diff;
        for(int i=0;i<diff;i++)
        {
            s.push(l1->val);
            l1=l1->next;
        }
        while(l1->next)
        {
            
            //cout<<1;
            s.push(l1->val+l2->val);
            l1=l1->next;
            l2=l2->next;
        }
        int sum=l1->val+l2->val;
        int carry=sum/10;
        ListNode *ans=new ListNode(sum%10);
        ListNode *dummy=ans;
        while(!s.empty())
        {
            int x=s.top()+carry;
            s.pop();
            ListNode *temp=new ListNode(x%10);
            ans->next=temp;
            ans=ans->next;
            carry=x/10;
        }
        if(carry){
            ListNode *temp=new ListNode(carry);
            ans->next=temp;
            ans=ans->next;
            ans->next=NULL;
        }
        return reverse(dummy);
        
        
        
    }
};