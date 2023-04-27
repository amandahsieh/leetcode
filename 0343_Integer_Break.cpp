/*------------------Author: Hsin-Yu Hsieh------------------*/
/*First:  dynamic programming      T:0 100%  M:6.1  56.18% */

class Solution {
public:
    int integerBreak(int n) {
        if(n==2)    return 1;
        if(n==3)    return 2;
        vector<int> ans(n+1);
        for(int i=0; i<=n; i++) ans[i] = i;
        for(int i=4; i<=n; i++){
            for(int j=1; j<i/2+1; j++){
                ans[i] = max(ans[i], ans[j]*ans[i-j]);
            }
        }
        return ans[n];
    }
};