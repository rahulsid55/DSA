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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return 0;
        ListNode *tor=head;
        ListNode *rab=head;
        if(rab->next==NULL)
        {
            return 0;
        }
        else
        {
        rab=rab->next;
        }
        while(tor!=rab)
        {
            if(tor==NULL)
            {
                return 0;
            }
            if(rab==NULL)
            {
                return 0;
            }  
            if(tor->next)
            {
                tor=tor->next;
            }
            else
            {
                return 0;
            }
            if(rab->next && rab->next->next)
            {
                rab=rab->next->next;
            }
            else
                return 0;
          
        }
        return 1;
        
    }
};