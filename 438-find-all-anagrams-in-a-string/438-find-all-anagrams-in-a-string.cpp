//Sliding window + map
class Solution {
    bool equal(vector<int> present,vector<int> freq)
    {
        for(int i=0;i<26;i++)
        {
            if(present[i]!=freq[i])
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
         vector<int> ans;
         int n=s.length();
        int m=p.length();
        if(n<m)
            return ans;
        vector<int> freq(26,0);
        for(int i=0;i<m;i++)
        {
            freq[p[i]-'a']++;
        }
        vector<int> present(26,0);
        for(int i=0;i<m;i++)
        {
            present[s[i]-'a']++;
        }
        if(equal(present,freq))
        {
            ans.push_back(0);
        }
        for(int i=m;i<n;i++)
        {
            present[s[i-m]-'a']--;
            present[s[i]-'a']++;
            if(equal(present,freq))
            {
                ans.push_back(i-m+1);
            }
        }
        return ans;
        
        
    }
};