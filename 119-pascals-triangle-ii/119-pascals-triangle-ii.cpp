class Solution {
public:
    vector<int> getRow(int rowIndex) {
          vector <int> ans(1);
        ans[0]=1;
        for(int i=1;i<=rowIndex;i++){
             vector<int> temp(i+1);
             for(int j=0;j<=i;j++){
                 if(j==0){
                     temp[j]=1;
                 }
                 else if(j==i){
                     temp[j]=1;
                 }
                 else{
                     temp[j]=ans[j]+ans[j-1];
                 }
             }
            ans.resize(i+1);
            for(int k=0;k<=i;k++){
                ans[k]=temp[k];
            }
        }
        return ans;
        
    }
};