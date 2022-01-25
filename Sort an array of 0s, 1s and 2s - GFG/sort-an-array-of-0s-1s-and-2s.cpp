// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
    int mid=0,l=0,r=n-1;
    while(mid<=r){
        if(a[mid]==0){
            swap(a[l],a[mid]);
            l++;
            mid++;
        }
        else if(a[mid]==2){
            swap(a[mid],a[r]);
            r--;
        }
        else{
            mid++;
        }
        
    }    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends