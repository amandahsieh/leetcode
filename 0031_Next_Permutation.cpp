/*---------------------Author: Hsin-Yu Hsieh----------------------*/
/*First Trial: Decreasing & swap & reverse  T:0 100% M:12.2 40.49%*/

/*First Trial: */
//Find the first decreasing from tail
//Find the smallest that is bigger -> swap
//reverse the remaining to tail
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n=nums.size()-1, i;
        for(i=n-1; i>=0; i--) if(nums[i]<nums[i+1])   break;
        if(i==-1)   {reverse(nums.begin(), nums.end()); return;}
		while(nums[i]>=nums[n])	n--;
		swap(nums[i], nums[n]);
	    reverse(nums.begin()+i+1, nums.end());
	    return;
    }
};