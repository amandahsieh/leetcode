/*-------------------------Author: Hsin-Yu Hsieh-------------------------*/
/*First Trial:  sort&unique, max consc.      T:82 91.27%    M:33.7 92.44%*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int start = 0, i;
        int ans = 0;
        for(i=0; i<nums.size(); i++){
            if((i-start) != (nums[i]-nums[start])){
                ans = max(ans, (i-start));
                start = i;
            }
        }
        ans = max(i-start, ans);
        return ans;
    }
};