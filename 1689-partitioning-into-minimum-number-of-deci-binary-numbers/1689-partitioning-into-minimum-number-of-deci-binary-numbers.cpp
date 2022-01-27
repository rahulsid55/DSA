class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(int i=0;i<n.length();i++){
            int x=n[i]-'0';
            maxi=max(x,maxi);
        }
        return maxi;
        
    }
};