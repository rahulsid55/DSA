class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int n1=houses.size();
        int n2=heaters.size();
        int ans=INT_MIN;
        for(int i=0;i<n1;i++){
            int x=houses[i];
            int d1=INT_MAX,d2=INT_MAX;
            int j=lower_bound(heaters.begin(),heaters.end(),x)-heaters.begin();
            if(j-1>=0){
                d1=x-heaters[j-1];
            }
            if(j<n2){
                d2=heaters[j]-x;
            }
            ans=max(ans,min(d1,d2));
            
        }
        return ans;
    }
};