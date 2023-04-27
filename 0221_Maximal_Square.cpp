/*----------------Author: Hsin-Yu Hsieh---------------*/
/*First trial: DP square rd  T:74,98.48% M 21.1,22.30%*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n = matrix[0].size(), ans=0, i, j;
        vector<vector<int>> area(m, vector<int>(n, 0));
        for(i=0; i<m; i++)  if(matrix[i][0]=='1') {ans=1; area[i][0]=1;} 
        for(j=1; j<n; j++)  if(matrix[0][j]=='1') {ans=1; area[0][j]=1;}
        for(i=1; i<m; i++){
            for(j=1; j<n; j++){
                if(matrix[i][j]=='0')    continue;
                int l = area[i][j-1], u = area[i-1][j];
                if(l==u)    area[i][j] = l+ (matrix[i-l][j-l]!='0');
                else        area[i][j] = min(l, u)+1;
                ans = max(ans, area[i][j]);
            }
        }
        return ans*ans;
    }
};