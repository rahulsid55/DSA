class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int x=0,n=encoded.size();
        
        for(int i=1;i<=n+1;i++){
            x=x^i;
        }
        for(int i=1;i<n;i+=2){
            x=x^encoded[i];
        }
        vector<int> ans;
        ans.push_back(x);
        for(int i=0;i<n;i++){
            ans.push_back(x^encoded[i]);
            x=x^encoded[i];
        }
        return ans;
        
    }
};