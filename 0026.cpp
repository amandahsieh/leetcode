/*-----------------------------Author: Hsin-Yu Hsieh-----------------------------*/
/*First Trial: Replace Duplicates & sort               T:12 76.14%  M:18.3 76.96%*/
/*Second Trial: Record cnt, unused->replace original   T:7 96.29%   M:18.2 93.87%*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num=nums.size(), tmp=0;
        vector<bool> cnt(205, 0);
        for(int i=0; i<nums.size(); i++){
            if(cnt[nums[i]+100])    num--;
            else{
                cnt[nums[i]+100]=true;
                nums[tmp++]=nums[i];
            }
        }
        return num;
    }
};

/*
First Trial: replace duplicates & sort
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num=nums.size();
        int last = 200;
        for (int i=1 ; i<nums.size() ; i++){
            if (nums[i]==nums[i-1] || nums[i]==last){
                last = nums[i];
                nums[i] = 200;
                num--;
            }
        }
        sort(nums.begin(), nums.end());
        return num;
    }
};
*/