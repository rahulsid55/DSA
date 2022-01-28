class Solution {
public:
    vector<int> minOperations(string boxes) {
        int balls=0,n=boxes.length();
        int left[n],right[n];
        left[0]=0;
        balls=boxes[0]-'0';
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+balls-(boxes[i-1]-'0');
            if(boxes[i-1]=='1'){
                left[i]+=1;
            }
            balls+=(boxes[i]-'0');
        }
        balls=boxes[n-1]-'0';
        right[n-1]=0;
          for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+balls-(boxes[i+1]-'0');
              if(boxes[i+1]=='1'){
                  right[i]+=1;
              }
            balls+=(boxes[i]-'0');
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=left[i]+right[i];
        }
        return ans;
    }
};