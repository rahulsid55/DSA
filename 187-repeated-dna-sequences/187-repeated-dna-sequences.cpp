class Solution {
public:
    
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int n=s.length();
        for(int i=0;i<n-10+1;i++){
           mp[s.substr(i,10)]++; 
        }
        vector<string> ans;
        for(auto it: mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};