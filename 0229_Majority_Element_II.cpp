/*----------------Author: Hsin-Yu Hsieh---------------*/
/*First trial: unordered_map  T:10,91.26%  M:16,17.75%*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)    mp[nums[i]]++;
        for(auto i:mp) {
            if(i.second>nums.size()/3)    ans.push_back(i.first);
        }
        return ans;
    }
};