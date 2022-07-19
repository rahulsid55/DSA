class Solution {
public:
    long long base = 101 , mod = 1011001110001111;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
         int L = 0 , R = max(nums1.size(),nums2.size()) , ans = 0;
         while(L<=R) {
              int m = (L+R)/2;
              if(good(nums1,nums2,m)) {
                    ans = m;
                    L = m + 1;
              }else {
                    R = m - 1; 
              }
         }
        return ans;
    }
    bool good(vector<int> &a,vector<int>&b,int m) {
         long long hash = 0 , power = 1;
         unordered_set<long long> ss;
         int l = 0;
         for(int i=0; i<a.size(); i++) {
             hash = ((hash*base)%mod + a[i])%mod;
                if(i>=m-1) {
                    ss.insert(hash);
                    hash = (hash - (a[l]*power)%mod)%mod;
                    if(hash<0) hash+=mod;
                    l++;
                }else {
                    power = (power * base) % mod;
                }
         }
         hash = 0 , l = 0;  
         for(int i=0; i<b.size(); i++) {
               hash = ((hash * base)%mod + b[i])%mod;
                if(i>=m-1) {
                     if(ss.find(hash)!=ss.end()) {
                         return true;
                     }
                    hash = (hash - (b[l]*power)%mod)%mod;
                    if(hash<0) hash+=mod;
                    l++;
                }
         }
        return false;
    }
};