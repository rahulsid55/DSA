class Solution {
public:
     vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        
        for(int i = 0; i < s.size(); i++) {
            string sub = s.substr(i, s.size());
            int r = startPos[0], c = startPos[1];
            int cnt = 0;
         
            for(int j = 0; j < sub.size(); j++) {
                if(sub[j] == 'U') r -= 1;
                if(sub[j] == 'R') c += 1;
                if(sub[j] == 'D') r += 1;
                if(sub[j] == 'L')  c -= 1;
                if(r >= 0 && r < n && c >= 0 && c < n)  cnt++; 
                else break;      
            }
        ans.push_back(cnt);   
        }
        return ans;
    }
};