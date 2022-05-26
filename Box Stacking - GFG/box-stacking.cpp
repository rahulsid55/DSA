// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    struct box{
        int l,w,h;
    };
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    bool static mysort(box a,box b){
        return ((a.l)*(a.w))>((b.l)*(b.w));
    }
    int maxHeight(int height[],int width[],int length[],int n)
    {
        box b[3*n];
        int index=0;
        for(int i=0;i<n;i++){
            b[index].h=height[i];
            b[index].l=max(width[i],length[i]);
            b[index].w=min(width[i],length[i]);
            index++;
            b[index].h=width[i];
            b[index].l=max(height[i],length[i]);
            b[index].w=min(length[i],height[i]);
            index++;
            b[index].h=length[i];
            b[index].l=max(width[i],height[i]);
            b[index].w=min(width[i],height[i]);
            index++;
        }
        n=3*n;
        sort(b,b+n,mysort);
        int dp[n];
        for(int i=0;i<n;i++){
            //cout<<b[i].l<<" "<<b[i].w<<" "<<b[i].h<<endl;
            dp[i]=b[i].h;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(b[i].l<b[j].l and b[i].w<b[j].w and dp[i]<(b[i].h+dp[j])){
                    dp[i]=b[i].h+dp[j];
                    //cout<<dp[i]<<" ";
                }
            }
        }
        int x=0;
        for(int i=0;i<n;i++){
            x=max(x,dp[i]);
        }
        return x;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends