class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n || arr[i]<arr[st.top()])){
                int x=st.top();
                st.pop();
                int y=st.empty()?-1:st.top();
                cout<<y<<" "<<x<<" "<<i<<endl;
                 ans += arr[x] * (long long)(x-y)*(i-x);
            }
            st.push(i);
            
        }
        ans = ans % (int)(1e9 + 7);
        return (int)ans;
    }
};