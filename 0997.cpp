/*--------------------------Author: Hsin-Yu Hsieh--------------------------*/
/*First Trial: Record #trusted and #trusting    T:172 94.15%  M:60.8 89.43%*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n+1);
        vector<int> trusted(n+1);
        for (int i=0; i<trust.size(); i++){
            trusting[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        for (int i=1; i<=n; i++){
            if (trusting[i]==0 && trusted[i]==n-1)  return i;
        }
        return -1;
    }
};