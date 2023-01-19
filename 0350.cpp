/*-----------------------Author: Hsin-Yu Hsieh------------------------*/
/*First Trial: bucket check & record times   T:7 69.69%  M:10.3 51.46%*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c(1005);
        vector<int> ans;
        for (int i=0 ; i<nums1.size() ; i++)    c[nums1[i]]++;
        for (int i=0 ; i<nums2.size() ; i++)    c[nums2[i]]+=2000;
        for (int i=0 ; i<=1000 ; i++){
            int times = min(c[i]/2000, c[i]%2000);
            for (int j=0 ; j<times ; j++)   ans.push_back(i);
        }
        return ans;
    }
};