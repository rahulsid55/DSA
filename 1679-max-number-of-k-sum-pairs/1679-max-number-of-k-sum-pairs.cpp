class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]+=1;
        }
        //int visited[n];
        int ct=0;
        //memset(visited,0,sizeof(visited));
        for(auto i: mp)
        {
            if((k-i.first)!=i.first and mp[k-i.first]>0)
            {
             ct+=min(mp[i.first],mp[k-i.first]);
             mp[i.first]=0;
             mp[k-i.first]=0;
            }
            else if((k-i.first)==i.first and mp[k-i.first]>0){
                ct+=mp[i.first]/2;
                mp[i.first]=0;
            }
        }
        return ct;
    }
};