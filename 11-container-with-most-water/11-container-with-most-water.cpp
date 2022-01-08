class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        int i=0,j=n-1;
        int maxx=0,water,h,width;
        while(i<j)
        {
            h=min(a[i],a[j]);
            width=j-i;
            water=h*width;
            maxx=max(water,maxx);
            a[i]>a[j]?j--:i++;
        }
        return maxx;
    }
};