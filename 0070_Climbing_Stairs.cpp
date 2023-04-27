/*----------------Author: Hsin-Yu Hsieh----------------*/
/*First Trial: Add n-1 & n-2      T:0 100%   M:6 70.27%*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> num(2,1);
        for (int i=2 ; i<=n ; i++){
            swap(num[0], num[1]);
            num[1]+=num[0];
        }
        return num[1];
    }
};