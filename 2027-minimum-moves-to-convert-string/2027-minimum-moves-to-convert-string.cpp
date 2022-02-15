class Solution {
public:
    int minimumMoves(string s) {
        int i=0,n=s.length();
        int j=2;
        int count=0;
        for(int i=0;i<n;i++){
            cout<<i;
            if(s[i]=='O'){
                continue;
            }
            else{
                count+=1;
                i=i+2;
                
            }
        }
        return count;
    }
};