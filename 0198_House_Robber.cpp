/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: Dynamic Programming    T:0 100.00%  M:7.9 29.51%*/
/*Second Trial: 2, array              T:2  48.84%  M:7.7 81.34%*/

//First Trial
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size(), m=0;
        if(len==1)  return nums[0];
        vector<int> sum(len);
        sum[0] = nums[0];
        sum[1] = nums[1];
        for(int i=2; i<len; i++){
            m = max(m, sum[i-2]);
            sum[i] = m + nums[i];
        }
        return max(sum[len-1], sum[len-2]);
    }
};

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int m=0;
        int sum[2] = {0, 0};
        for(int i=0; i<nums.size(); i++){
            m = max(m, sum[0]);
            sum[0] = sum[1];
            sum[1] = m + nums[i];
        }
        return max(sum[0], sum[1]);
    }
};
*/