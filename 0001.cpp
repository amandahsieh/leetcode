/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First  Trial: brutal             T:691 19.45%   M:10.1 88.22%*/
/*Second Trial: brutal optimize    T:70  48.9 %   M:10   96.75%*/
/*Third  Trial: brutal optimize    T:11  90.2 %   M:11.6 12.76%*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        vector<int> sum(2);
        for (int i=0; i<nums.size(); i++){
            int tmp = target - nums[i];
            if (dic[tmp]==0){
                dic[nums[i]]=i+1;
            }  
            else{
                sum[0]=dic[tmp]-1;
                sum[1]=i;
                break;
            }
        }
        return sum;
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