/*----------------Author: Hsin-Yu Hsieh---------------*/
/*First trial: Sort & Check T:105,74.91% M 46.6,92.85%*/
/*Second trial: set (hash) slower*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>dic;
        for (int i=0; i<nums.size(); i++){
            if(dic.find(nums[i])!=dic.end())    return true;
            dic.insert(nums[i]);
        }
        return false;
    }
};

/*
First Trial: Sort & Check the adjacent
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=1 ; i<nums.size() ; i++){
            if (nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};
*/