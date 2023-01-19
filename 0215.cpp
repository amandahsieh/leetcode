/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: nth element         T:58 99.98%     M:45.5 89.9%*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end()-k, nums.end());
        return nums[nums.size()-k];
    }
};