/*----------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial:  for loops            T:1517  5%       M:15 39.22%*/
/*Second Trial: for loops            T:  79 96.88%    M:15 39.22%*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix[0].size()-1, m=matrix.size(), t;
        while(i<m && j>=0){
            t = matrix[i][j];
            if(t==target)    return true;
            if(t<target)     i++;
            else    j--;
        }
        return false;
    }
};

/*
First Trial:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, j, s=0, m=matrix.size(), n=matrix[0].size();
        int last = n, t;
        for(i=0; i<m; i++){
            if(matrix[i][n-1]<target)   continue;
            int tmp = last;
            for(j=0; j<tmp; j++){
                t=tmp-j-1;
                if(matrix[i][j]==target||matrix[i][t]==target)  return true;
                if(matrix[i][t]>target)    last = t;
                if(t<=j)    break;
            }
        }
        return false;
    }
};
*/