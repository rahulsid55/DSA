class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX,n=cards.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp[cards[i]]>0){
                //cout<<cards[i]<<" ";
                ans=min(i-mp[cards[i]]+2,ans);
            }
                mp[cards[i]]=i+1;
        }
        return ans==INT_MAX?-1:ans;
        
    }
};