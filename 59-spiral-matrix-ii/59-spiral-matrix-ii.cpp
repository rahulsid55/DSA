class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,top=n-1,bot=0,right=n-1;
        int i=0;
        vector<vector<int>> mat(n,vector<int> (n));
        int x=1;
        while(left<=right and top>=bot){
            if(i==0){
                for(int j=bot;j<=top;j++){
                    mat[left][j]=x++;
                }
                left++;
            }
            if(i==1){
                for(int j=left;j<=right;j++){
                    mat[j][top]=x++;
                }
                top--;
            }
            if(i==2){
                for(int j=top;j>=bot;j--){
                    mat[right][j]=x++;
                }
                right--;
            }
            if(i==3){
                for(int j=right;j>=left;j--){
                    mat[j][bot]=x++;
                }
                bot++;
            }
            i=(i+1)%4;
        }
        return mat;
    }
};