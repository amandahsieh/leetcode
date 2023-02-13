/*-----------------------Author: Hsin-Yu Hsieh-----------------------*/
/*First Trial:  Prefix sum & Pre-smallest  T:127 48.65%  M:70.5 5.19%*/
/*Second Trial: Prefix sum & tmp smallest  T:113 84.35%  M:67.7 61.4%*/
/*Third Trial:  Sliding Window             T:235 14%     M:67.8 61.4%*/
/*Fourth Trial: tmpsum & ans               T: 95 99.50%  M:67.8 15.77%*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int ans = INT_MIN, tmp=INT_MIN;
        for(auto i:nums){
            tmp = (tmp<0)? i:tmp+i;
            ans = max(ans, tmp);
        }
        return ans;
    }
};

/*
First Trial: Prefix sum & Prefix smallest sum (2 vectors)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], n=nums.size();
        vector<int> small(n+1, INT_MAX);
        small[0] = 0;
        for(int i=1; i<n; i++)  nums[i] += nums[i-1];
        for(int i=0; i<n; i++)  small[i+1] = min(small[i], nums[i]);
        for(int i=1; i<nums.size(); i++){
            ans = max(ans, nums[i]-small[i]);
        }
        return ans;
    }
};
*/

/*
Second Trial: Prefix sum & dynamic small
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], small=0;
        for(int i=1; i<nums.size(); i++){
            small = (small>nums[i-1])? nums[i-1]:small;
            nums[i] += nums[i-1];
            ans = (nums[i]-small>ans)? nums[i]-small:ans;
        }
        return ans;
    }
};
*/

/*
Third Trial: Sliding Window
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, j=0, sum=0, ans = INT_MIN;
        while(i<=j && j<nums.size()){
            sum += nums[j];
            if(sum<nums[j]){
                j=++i;
                sum = nums[i];
            }
            j++;
            ans = max(ans, sum);
        }
        return ans;
    }
};
*/