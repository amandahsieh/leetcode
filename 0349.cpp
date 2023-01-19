/*------------------------Author: Hsin-Yu Hsieh----------------------*/
/*First Trial: Bucket check (used)         T:5 79.57%   M:10.2 62.19%*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num(1050);
        vector<int> ans;
        for (int i=0 ; i<nums1.size() ; i++)    num[nums1[i]]++;
        for (int i=0 ; i<nums2.size() ; i++){
            if (num[nums2[i]]<1100) num[nums2[i]]+=2050;
        }    
        for (int i=0 ; i<=1000 ; i++)    if (num[i]>=2051)  ans.push_back(i);
        return ans;
    }
};