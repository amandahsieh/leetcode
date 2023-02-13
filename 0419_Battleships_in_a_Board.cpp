/*-------------------Author: Hsin-Yu Hsieh-----------------*/
/*First Trial: DFS, No. Islands      T:4 96.82%  M:8 89.82%*/

class Solution {
public:
	int m, n;
	void dfs(vector<vector<char>>& board, int x, int y){
        if(x<0 || y<0 || x>=m || y>=n || board[x][y]=='.')     return;
        board[x][y]='.';
        dfs(board, x-1, y);
        dfs(board, x, y-1);
        dfs(board, x+1, y);
        dfs(board, x, y+1);
	}
    int countBattleships(vector<vector<char>>& board) {
	    int ans = 0, i, j;
	    m = board.size();
	    n = board[0].size();
        for(i=0; i<m; i++){
		    for(j=0; j<n; j++){
			    if(board[i][j]== 'X'){
		            dfs(board, i, j);
		            ans++;
	            }
		    }
	    }
	    return ans;
    }
};