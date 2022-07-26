class Solution {
public:
    bool isequal(map<char,int> a,map<char,int> b){
        for(int i=0;i<26;i++){
            if(a['a'+i]!=b['a'+i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int k=s1.length();
        map<char,int> mp1,mp2;
        for(int i=0;i<k;i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if(isequal(mp1,mp2)) return true;
        for(int i=k;i<s2.length();i++){
            mp2[s2[i-k]]--;
            mp2[s2[i]]++;
            if(isequal(mp1,mp2)) return true;
        }
        return false;
        
        
    }
};