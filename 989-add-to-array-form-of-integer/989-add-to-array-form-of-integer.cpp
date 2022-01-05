class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int x) {
        int carry=0,n=num.size();
        for(int i=n-1;i>=0;i--)
        {
            int k=x%10;
            int sum=num[i]+k+carry;
            x/=10;
            carry=(sum)/10;
            num[i]=sum%10;
        }
        while(x)
        {
            int k=x%10;
            int sum=k+carry;
            x/=10;
            num.insert(num.begin(),sum%10);
            carry=sum/10;
        }
        if(carry)
        {
            num.insert(num.begin(),carry);
        }
        return num;
    }
};