/*faster but take more space*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int ans = nums.size()*(nums.size()+1)/2;
        for (int i=0 ; i<nums.size() ; i++){
            ans-=nums[i];
        }
        return (int) ans;
    }
};

/*medium speed and medium space*/
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i]!=i) return i;
        }
        return nums.size();
    }
};
*/