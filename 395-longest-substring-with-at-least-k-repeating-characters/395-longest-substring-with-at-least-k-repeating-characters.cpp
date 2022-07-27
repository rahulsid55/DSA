class Solution {
public:
    int solve(string s,int l,int r,int k){
        if(r==s.length()) return 0;
        if(l>=r) return 0;
        //cout<<l<<" "<<r<<endl;
        int count[26]={0};
        for(int i=l;i<=r;i++){
            count[s[i]-'a']++;
        }
        for(int i=l;i<=r;i++){
            if(count[s[i]-'a']<k){
                int j=i;
                while(j<r and count[s[j]-'a']<k) j++;
                return max(solve(s,l,i-1,k),solve(s,j,r,k));
            }
        }
        return r-l+1;
    }
    int longestSubstring(string s, int k) {
        if(k==1) return s.length();
        return solve(s,0,s.length()-1,k);
        
    }
};