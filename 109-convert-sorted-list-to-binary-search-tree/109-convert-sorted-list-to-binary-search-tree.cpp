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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     map<int,ListNode *> mp;
    TreeNode *solve(ListNode *head,int l,int h){
        if(l>h) return NULL;
        if(l==h){
            return new TreeNode(mp[l]->val);
        }
        int mid=(l+h)/2;
        TreeNode *root=new TreeNode(mp[mid]->val);
        root->left=solve(head,l,mid-1);
        root->right=solve(head,mid+1,h);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        int l=0,h=0;
        ListNode *temp=head;
       
        while(temp){
            mp[h]=temp;
            temp=temp->next;
            h++;
        }
        return solve(head,l,h-1);
        
    }
};