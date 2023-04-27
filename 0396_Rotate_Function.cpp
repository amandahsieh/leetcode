/*----------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: dynamic programming    T:149 90.25%  M:95.8 62.41%*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        int dp=0;
        for(int i=0; i<len; i++){
            dp+=nums[i]*i;
            sum+=nums[i];
        }
        int ans = dp;
        for(int k=0; k<len-1; k++){
            dp = dp-sum+nums[k]*len;
            ans = max(ans, dp);
        }
        return ans;
    }
};