class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1,i=1,j=nums.size()-1;
        while(i<=j){
            if(count==2 and nums[i]==nums[i-1]){
                int t=nums[j];
                int k=i;
                while(k<j){
                    nums[k]=nums[k+1];
                    k++;
                    
                }
                j--;
                
            }
            else{
                if(nums[i]==nums[i-1]){
                    count++;
                }
                else{
                    count=1;
                }
             i++;   
            }
        }
            return j+1;
    }
};