/*----------------Author: Hsin-Yu Hsieh----------------*/
/*First Trial: binary search  T:36 88.7%  M:27.6 15.99%*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, l = nums.size()-1;
        while(s<=l){
            int m = (s + l)/2;
            if (nums[m]<target)         s = m+1;
            else if (nums[m]>target)    l = m-1;
            else   return m;
        }
        return -1;
    }
};