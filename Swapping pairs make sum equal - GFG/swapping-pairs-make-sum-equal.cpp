// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        sort(A,A+n);
        sort(B,B+m);
        long long x=0,y=0;
        for(int i=0;i<n;i++){
            x+=A[i];
        }
        for(int j=0;j<m;j++){
            y+=B[j];
        }
        int l=0,r=0;
        //if(target==0) return -1;
        while(l<n and r<m){
             int p=x-A[l]+B[r];
             int q=y-B[r]+A[l];
             if(p==q) return 1;
             if(p>q){
                 l++;
             }
             else{
                 r++;
             }
        }
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends