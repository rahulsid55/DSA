class Solution {
public:
    bool possible(int mid,vector<int> weights,int days){
        int temp=1,sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                temp++;
                sum=weights[i];
                if(sum>mid) return false;
            }
            else{
                sum+=weights[i];
            }
        }
        if(temp>days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,h=0,n=weights.size();
        for(auto it: weights){
            h+=it;
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(mid,weights,days)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};