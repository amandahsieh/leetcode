class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector <vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i=0; i<intervals.size(); i++){
            int tmp = ans.back()[1];
            if(tmp>=intervals[i][0] && tmp<intervals[i][1]){
                ans.back()[1] = intervals[i][1];
            }
            else if (tmp<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};