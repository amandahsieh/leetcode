/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: DFS & Record & Turn   T:30 25.92%  M:37.1  5.1% */
/*Second Trial: DFS border => DFS    T:14 74.41%  M:13.7 12.81%*/
/*Third Trial: Stack (border)        T:11 91.86%  M:10.2 54.32%*/
/*Fourth Trial: DFS border           T: 9 95.11%  M: 9.9 95.85%*/

class Solution {
public:
    vector<vector<bool>> been;
    int m, n;
    void dfs(int x, int y, vector<vector<char>>& board){
        if(board[x][y]=='O'){
            board[x][y] = 'b';
            if(y+1<n ) dfs(x, y+1, board);
            if(x+1<m ) dfs(x+1, y, board);
            if(x-1>=0) dfs(x-1, y, board);
            if(y-1>=0) dfs(x, y-1, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> tmp;
        int i, j;
        for(i=0; i<m; i++){
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }
        for(j=0; j<n; j++){
            dfs(0, j, board);
            dfs(m-1, j, board);
        }
        for(i=0; i<board.size(); i++){
            for(j=0; j<board[i].size(); j++){
                if(board[i][j]=='b') board[i][j]='O';
                else if(board[i][j]=='O')   board[i][j]='X';
            }
        }
    }
};

/*
First Trial : DFS & Record & Turn
class Solution {
public:
    vector<vector<bool>> been;
    void dfs(int x, int y, vector<vector<char>>& board, int& border, vector<vector<int>>& tmp){
        been[x][y] = 1;
        tmp.push_back({x, y});
        if(x==0 || x==board.size()-1 || y==0 || y==board[0].size()-1)   border=1;
        if(y+1<board[0].size() && board[x][y+1]=='O' && !been[x][y+1]) dfs(x, y+1, board, border, tmp);
        if(x+1<board.size()    && board[x+1][y]=='O' && !been[x+1][y]) dfs(x+1, y, board, border, tmp);
        if(x-1>=0              && board[x-1][y]=='O' && !been[x-1][y]) dfs(x-1, y, board, border, tmp);
        if(y-1>=0              && board[x][y-1]=='O' && !been[x][y-1]) dfs(x, y-1, board, border, tmp);
    }
    void solve(vector<vector<char>>& board) {
        been.resize(board.size(), vector<bool>(board[0].size(), 0));
        vector<vector<int>> tmp;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                int border = 0;
                tmp.clear();
                if(board[i][j]=='O' && !been[i][j]){
                    dfs(i, j, board, border, tmp);
                    if(!border) for(int k=0; k<tmp.size(); k++) board[tmp[k][0]][tmp[k][1]]='X';
                }
            }
        }
    }
};
*/

/*
Second Trial: DFS border => DFS
class Solution {
public:
    vector<vector<bool>> been;
    int m, n;
    void dfs_b(int x, int y, vector<vector<char>>& board){
        been[x][y] = 1;
        if(y+1<n  && board[x][y+1]=='O' && !been[x][y+1]) dfs_b(x, y+1, board);
        if(x+1<m  && board[x+1][y]=='O' && !been[x+1][y]) dfs_b(x+1, y, board);
        if(x-1>=0 && board[x-1][y]=='O' && !been[x-1][y]) dfs_b(x-1, y, board);
        if(y-1>=0 && board[x][y-1]=='O' && !been[x][y-1]) dfs_b(x, y-1, board);
    }
    void dfs(int x, int y, vector<vector<char>>& board){
        been[x][y] = 1;
        if(y+1<board[0].size() && board[x][y+1]=='O' && !been[x][y+1]) dfs(x, y+1, board);
        if(x+1<board.size()    && board[x+1][y]=='O' && !been[x+1][y]) dfs(x+1, y, board);
        if(x-1>=0              && board[x-1][y]=='O' && !been[x-1][y]) dfs(x-1, y, board);
        if(y-1>=0              && board[x][y-1]=='O' && !been[x][y-1]) dfs(x, y-1, board);
        board[x][y] = 'X';
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        been.resize(board.size(), vector<bool>(board[0].size(), 0));
        vector<vector<int>> tmp;
        for(int i=0; i<m; i++)  if(board[i][0]=='O'   && !been[i][0])   dfs_b(i, 0, board);
        for(int i=0; i<n; i++)  if(board[0][i]=='O'   && !been[0][i])   dfs_b(0, i, board);
        for(int i=0; i<m; i++)  if(board[i][n-1]=='O' && !been[i][n-1]) dfs_b(i, n-1, board);
        for(int i=0; i<n; i++)  if(board[m-1][i]=='O' && !been[m-1][i]) dfs_b(m-1, i, board);

        for(int i=1; i<board.size()-1; i++){
            for(int j=1; j<board[i].size()-1; j++){
                if(!been[i][j]) dfs(i, j, board);
            }
        }
    }
};
*/

/*
Third Trial: Stack (border)
class Solution {
public:
    vector<vector<bool>> been;
    stack<pair<int, int>> pos;
    int m, n;
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        int i, j;
        been.resize(m,vector<bool>(n,0));
        for(i=0; i<=m-1; i++)    if(board[i][0]  =='O' && !been[i][0])  {pos.push({i, 0})  ; been[i][0]  =1;}
        for(i=0; i<=m-1; i++)    if(board[i][n-1]=='O' && !been[i][n-1]){pos.push({i, n-1}); been[i][n-1]=1;}
        for(i=0; i<=n-1; i++)    if(board[0][i]  =='O' && !been[0][i])  {pos.push({0, i})  ; been[0][i]  =1;}
        for(i=0; i<=n-1; i++)    if(board[m-1][i]=='O' && !been[m-1][i]){pos.push({m-1, i}); been[m-1][i]=1;}
        while(!pos.empty()){
            int x=pos.top().first, y=pos.top().second;
            pos.pop();
            if(x>0&&board[x-1][y]=='O'&&!been[x-1][y])  {pos.push({x-1, y}); been[x-1][y]=1;}
            if(y>0&&board[x][y-1]=='O'&&!been[x][y-1])  {pos.push({x, y-1}); been[x][y-1]=1;}
            if(x<m-1&&board[x+1][y]=='O'&&!been[x+1][y]){pos.push({x+1, y}); been[x+1][y]=1;}
            if(y<n-1&&board[x][y+1]=='O'&&!been[x][y+1]){pos.push({x, y+1}); been[x][y+1]=1;}
        }
        for(i=1; i<m-1; i++){
            for(j=1; j<n-1; j++){
                if(!been[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
*/