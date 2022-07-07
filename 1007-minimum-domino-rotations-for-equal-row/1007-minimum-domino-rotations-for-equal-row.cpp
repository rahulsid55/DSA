class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& down) {
        int count[7]={0};
        int n=top.size();
        for(int i=1;i<=6;i++){
            for(int j=0;j<n;j++){
                if(top[j]==i or down[j]==i){
                    count[i]++;
                }
            }
        }
        int mini=INT_MAX;
        for(int i=1;i<=6;i++){
            if(count[i]==n){
                int simi=0;
                int ct=0;
                for(int j=0;j<n;j++){
                    if(top[j]==i and down[j]==i){
                        simi++;
                    }
                    else{
                        if(top[j]==i){
                            ct++;
                        }
                    }
                }
                mini=min({mini,n-simi-ct,ct});
            }
        }
        return mini==INT_MAX?-1:mini;
        
    }
};