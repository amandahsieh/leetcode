/*----------------------Author: Hsin-Yu Hsieh-----------------------*/
/*First Trial: Farest Possible Sources   T:281 38.33%  M:17.2 39.64%*/
/*Second Trial: DP: current & farest     T:10  96.94%  M:16.6 83.73%*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len==1)  return 0;
        int farest=nums[0], cur=nums[0], i=0, ans=1;
        while(i<len-1){
            if(farest<nums[i]+i)    farest = nums[i]+i;
            if(i++==cur){
                ans++;
                cur = farest;
            }
        }
        return ans;
    }
};

/*
First Trial: Farest possible sources
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> from(nums.size());
        for(int i=nums.size()-2; i>=0; i--){
            for(int j=1; j<=nums[i]; j++){
                if(i+j>=nums.size())    break;
                from[i+j] = i;
            }
        }
        int tmp=nums.size()-1, ans=0;
        while(tmp>0){
            tmp = from[tmp];
            ans++;
        }
        return ans;
    }
};
*/