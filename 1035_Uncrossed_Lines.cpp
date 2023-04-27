/*------------------------Author: Hsin-Yu Hsieh------------------------*/
/*First Trial: Longest Common Subsequence     T:8 96.48%  M:13.1 37.50%*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i, j;
        vector<vector<int>> l(m+1, vector<int> (n+1));
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                l[i+1][j+1] = (nums1[i]==nums2[j])? l[i][j]+1:max(l[i][j+1], l[i+1][j]);
            }
        }
        return l[m][n];
    }
};