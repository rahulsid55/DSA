class Solution {
public:
    int candy(vector<int>& rating) {
        
        int i=1,n=rating.size();
        long long cand=n;
        while(i<n){
            while(i<n and rating[i]==rating[i-1]){
                i++;
                
            }
            int peak=0;
            while(i<n and rating[i]>rating[i-1]){
                peak++;
                cand+=peak;
                i++;
                if(i==n) return cand;
            }
            int valley=0;
            while(i<n and rating[i]<rating[i-1]){
                valley++;
                cand+=valley;
                i++;
            }
            cand-=min(valley,peak);
        }
        return cand;
        
    }
};