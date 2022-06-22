class Solution {
public:
    int MSB(int n){
        int ans=0;
        while(n){
            ans++;
            n=n>>1;
        }
        return ans-1;
    }
    int rangeBitwiseAnd(int left, int right) {
         int x=MSB(left);
         int y=MSB(right);
         if(right==0) return 0;
         int ans=left;
        if(x==y){
            for(int i=left;i<right;i++){
                ans=ans&i;
            }
            ans=ans&right;
            return ans;
        }
        return 0;
        
    }
};