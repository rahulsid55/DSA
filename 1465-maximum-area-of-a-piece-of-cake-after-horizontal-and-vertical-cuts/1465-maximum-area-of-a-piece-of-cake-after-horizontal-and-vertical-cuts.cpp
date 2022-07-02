class Solution {
    int const mod=1e9+7;
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int n=hc.size();
        int m=vc.size();
        int diff1[n+1];
        int diff2[m+1];
        
        diff1[0]=hc[0];
        int maxh=diff1[0];
        for(int i=1;i<n;i++){
            diff1[i]=hc[i]-hc[i-1];
            maxh=max(maxh,diff1[i]);
            
        }
        diff1[n]=h-hc[n-1];
        maxh=max(maxh,diff1[n]);
        diff2[0]=vc[0];
        int maxv=diff2[0];
        for(int i=1;i<m;i++){
            diff2[i]=vc[i]-vc[i-1];
            maxv=max(maxv,diff2[i]);
        }
        diff2[m]=w-vc[m-1];
        maxv=max(maxv,diff2[m]);
        
        return ((long)maxh)*((long)maxv)%mod;
        
    }
};