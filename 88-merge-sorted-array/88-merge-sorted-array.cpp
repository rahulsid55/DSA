class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=m-1,r=n-1,k=nums1.size()-1;
        while(l>=0 and r>=0){
            if(nums1[l]<nums2[r]){
                nums1[k--]=nums2[r--];
            }
            else{
                nums1[k--]=nums1[l--];
            }
        }
        while(l>=0){
            nums1[k--]=nums1[l--];
        }
        while(r>=0){
            nums1[k--]=nums2[r--];
        }
    }
};