class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,n1=s.size(),n2=t.size();
        while(i<n1 and j<n2){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        if(i==n1) return 1;
        return 0;
    }
};