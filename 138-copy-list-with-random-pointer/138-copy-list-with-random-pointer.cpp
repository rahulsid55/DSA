class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
             return head;
        
        Node* node=new Node(head->val);
        Node* temp=node;
        Node* t=head;
        
        //inserting duplicate nodes
        while(head)
        {
            Node* k=head->next;
            head->next=node;
            node->next=k;
            head=head->next->next;
            if(head)
               node=new Node(head->val);
        }
        head=t;

        
        //assigning proper random pointers
        while(head)
        {
      
        if(head->next&&head->random)
        {
             head->next->random=head->random->next;
        }
             head=head->next->next;
        }
        
        head=t;
        
        Node* res=new Node(0);
        t=res;
        //restoring lists
        while(head)
        {
            res->next=head->next;
            res=res->next;
            head->next=head->next->next;
            head=head->next;
        }
        

        
        return t->next;
       
    }
};