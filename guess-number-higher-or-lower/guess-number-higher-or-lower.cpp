/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
typedef long long ll;
class Solution {
public:
    int guessNumber(int n) {
        ll l=1,h=n;
         while(1)
         {
             ll mid=(l+h)/2;
             //cout<<mid<<" ";
             ll x=guess(mid);
             if(x==0)
             {
                 return mid;
                 break;
             }
             else if(x==-1)
             {
                 h=mid-1;
             }
             else
             {
                 l=mid+1;
             }
         }
        return -1;
        
    }
};