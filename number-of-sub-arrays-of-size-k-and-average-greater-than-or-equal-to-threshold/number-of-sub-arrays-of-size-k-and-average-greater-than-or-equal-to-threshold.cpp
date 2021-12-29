class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0,count=0,n=arr.size();
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if((sum/k)>=threshold)
        {
            count++;
        }
        for(int i=k;i<n;i++){
            sum+=arr[i];
            sum-=arr[i-k];
            if((sum/k)>=threshold)
           {
            count++;
           }
        }
        return count;
        
    }
};