/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: sort, add, '0'       T:9 74.86%    M:11.1 88.55%*/
class Solution {
public:
    struct mycompare{
        bool operator()(const int a, const int b){
            string sa = to_string(a);
            string sb = to_string(b);
            return sa+sb>sb+sa;
        }
    };
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), mycompare());
        for (int i=0 ; i<nums.size() ; i++){
            ans+=to_string(nums[i]);
        }
        if (ans[0]=='0')    ans = '0';
        return ans;
    }
};