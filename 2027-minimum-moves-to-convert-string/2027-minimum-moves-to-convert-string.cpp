class Solution {
public:
    int minimumMoves(string s) {
        int i=0,n=s.length();
        int j=2;
        int count=0;
        for(int i=0;i<n;){
            if(s[i]=='O'){
                i++;
            }
            else{
                count+=1;
                i=i+3;
                
            }
        }
        return count;
    }
};