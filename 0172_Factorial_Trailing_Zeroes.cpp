/*-----------------Author: Hsin-Yu Hsieh-----------------*/
/*First Trial: count '5's        T:0 100%    M:5.8 91.43%*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n)    ans+=(n/=5);
        return ans;
    }
};