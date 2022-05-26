// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    int minSum(int arr[], int n){
        if(n<=4) return *min_element(arr,arr+n);
        int e,a=arr[0],b=arr[1],c=arr[2],d=arr[3];
        for(int i=4;i<n;i++){
            e=arr[i]+min({a,b,c,d});
            a=b;
            b=c;
            c=d;
            d=e;
        }
        return min({a,b,c,d,e});
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends