class Solution {
public:
    int reverse(int y) {
        
        int z=0;
        while(y)
        {
            if (z > (INT_MAX / 10) || z < (INT_MIN / 10))
            {
                return 0;
            }
            z=z*10+y%10;
            y=y/10;
        }
        return z;
        
        
    }
};