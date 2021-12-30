class node{
    public:
    node *links[2];
    node(){
        for(int i=0;i<2;i++){
            links[i]=NULL;
        }
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        node *root=new node();
        for(int j=0;j<n;j++){
            int num=nums[j];
            node *temp=root;
            for(int i=31;i>=0;i--)
            {
                int x=(num>>i)&1;
                if(temp->links[x]==NULL)
                {
                    temp->links[x]=new node();
                }
                temp=temp->links[x];
                
            }
        }
        int maxi=0;
        for(int j=0;j<n;j++){
            node *temp=root;
            int ans=0;
            for(int i=31;i>=0;i--){
                int bit=(nums[j]>>i)&1;
                if(bit==0)
                {
                    if(temp->links[1]!=NULL)
                    {
                      ans+=1<<i;
                      temp=temp->links[1];
                    }
                    else{
                        temp=temp->links[0];
                    }
                }
                if(bit==1)
                {
                    if(temp->links[0]!=NULL)
                    {
                      ans+=1<<i;
                      temp=temp->links[0];
                    }
                    else{
                        temp=temp->links[1];
                    }
                }
                
            }
            maxi=max(maxi,ans);
            
        }
        return maxi;
    }
};