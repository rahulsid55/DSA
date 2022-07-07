class Solution {
public:
    int numSplits(string s) {
        map<char,int> mp1,mp2;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
        }
        int ct=0;
        for(int i=0;i<n;i++){
            mp1[s[i]]--;
            mp2[s[i]]++;
            if(mp1[s[i]]==0){
                mp1.erase(s[i]);
            }
            if(mp1.size()==mp2.size()){
                ct++;
            }
        }
        return ct;
        
    }
};