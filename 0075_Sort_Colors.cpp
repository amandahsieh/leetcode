/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: #of each color, set nums  T:0 100%  M:8.2 91.66%*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans(nums.size());
        int color[3]={0,0,0};
        int i;
        for (i=0; i<nums.size() ; i++)  color[nums[i]]++;
        for (i=0; i<color[0]; i++)  nums[i]=0;
        for (i=0; i<color[1]; i++)  nums[i+color[0]]=1;
        for (i=0; i<color[2]; i++)  nums[i+color[0]+color[1]]=2;
    }
};