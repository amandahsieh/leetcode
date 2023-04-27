/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First  Trial: brutal             T:691 19.45%   M:10.1 88.22%*/
/*Second Trial: brutal optimize    T: 70 48.9 %   M:10   96.75%*/
/*Third  Trial: brutal optimize    T:  4 99.2 %   M:11.4 12.44%*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        unordered_map<int, int> n;
        int i, l=nums.size();
        for(i=0; i<l; i++){
            if(n[target-nums[i]])  return {n[target-nums[i]]-1, i};  
            n[nums[i]]=i+1;
        }
        return {0, 0};
    }
};

/*
Second Trial: Brutal Optimized
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum(2);
        for (int i=0 ; i<nums.size()-1 ; i++){
            int tmp = target - nums[i];
            int p = find(nums.begin()+i+1, nums.end(), tmp) - nums.begin();
            if (p<nums.size()){
                sum[0] = i;
                sum[1] = p;
                break;
            }
        }
        return sum;
    }
};
*/

/*
First Trial: Brutal
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum;
        for (int i=0 ; i<nums.size()-1 ; i++){
            for (int j=i+1 ; j<nums.size() ; j++){
                if (nums[i] + nums[j] == target){
                    sum.push_back(i);
                    sum.push_back(j);
                    break;
                }
            }
        }
        return sum;
    }
};
*/