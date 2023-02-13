/*-------------------Author: Hsin-Yu Hsieh-------------------*/
/*First Trial:  Recursive         T:471 5.19%  M:185.8  6.10%*/
/*Second Trial: DFS & cal         T:  7 100%   M: 11.9 72.13%*/

class Solution {
public:
    int m, n;
    void adj(vector<vector<char>>& b, int x, int y){
        int cnt = 0;
        if(x>0 && y>0)      cnt += b[x-1][y-1]=='M';
        if(x>0 && y+1<n)    cnt += b[x-1][y+1]=='M';
        if(x+1<m && y>0)    cnt += b[x+1][y-1]=='M';
        if(x+1<m && y+1<n)  cnt += b[x+1][y+1]=='M';
        if(x>0)             cnt += b[x-1][y]=='M';
        if(x+1<m)           cnt += b[x+1][y]=='M';
        if(y>0)             cnt += b[x][y-1]=='M';
        if(y+1<n)           cnt += b[x][y+1]=='M';
        b[x][y] = cnt? '0'+cnt:'B';
    }
    void dfs(vector<vector<char>>& b, int x, int y){
        if(x<0||y<0||x>=m||y>=n||b[x][y]!='E')  return;
        adj(b, x, y);
        if(b[x][y]!='B')    return;
        dfs(b, x-1, y-1);
        dfs(b, x-1, y+1);
        dfs(b, x+1, y-1);
        dfs(b, x+1, y+1);
        dfs(b, x-1, y);
        dfs(b, x+1, y);
        dfs(b, x, y-1);
        dfs(b, x, y+1);
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        if(board[click[0]][click[1]]=='M')    board[click[0]][click[1]]='X';
        else    dfs(board, click[0], click[1]);
        return board;
    }
};

/*
First Trial: Recursive 
class Solution {
public:
    int m, n;
    vector<vector<int>> adj;
    vector<int> c(int a, int b){
        vector<int> myv{a, b};
        return myv;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int i=click[0], j=click[1];
        adj.resize(m, vector<int>(n, -1));
        if(board[i][j]=='M'){
            board[i][j] = 'X';
            return board;
        }
        else if(board[i][j]=='E'){
            if(adj[i][j]<0){
                adj[i][j]=0;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]=='M')    adj[i][j]++;
                if(i-1>=0 && j+1< n && board[i-1][j+1]=='M')    adj[i][j]++;
                if(i+1< m && j-1>=0 && board[i+1][j-1]=='M')    adj[i][j]++;
                if(i+1< m && j+1< n && board[i+1][j+1]=='M')    adj[i][j]++;
                if(i-1>=0 && board[i-1][j]=='M')    adj[i][j]++;
                if(i+1< m && board[i+1][j]=='M')    adj[i][j]++;
                if(j-1>=0 && board[i][j-1]=='M')    adj[i][j]++;
                if(j+1< n && board[i][j+1]=='M')    adj[i][j]++;
            }
            
            if(adj[i][j]==0){
                board[i][j]='B';
                if(i-1>=0 && j-1>=0){vector<int> tmpv{i-1, j-1};  board = updateBoard(board, tmpv);}
                if(i-1>=0 && j+1< n){vector<int> tmpv{i-1, j+1};  board = updateBoard(board, tmpv);}
                if(i+1< m && j-1>=0){vector<int> tmpv{i+1, j-1};  board = updateBoard(board, tmpv);}
                if(i+1< m && j+1< n){vector<int> tmpv{i+1, j+1};  board = updateBoard(board, tmpv);}
                if(i-1>=0){vector<int> tmpv{i-1, j};    board = updateBoard(board, tmpv);}
                if(i+1< m){vector<int> tmpv{i+1, j};    board = updateBoard(board, tmpv);}
                if(j-1>=0){vector<int> tmpv{i, j-1};    board = updateBoard(board, tmpv);}
                if(j+1< n){vector<int> tmpv{i, j+1};    board = updateBoard(board, tmpv);}
            }
            else    board[i][j]='0'+adj[i][j];
        }
        return board;
    }
};
*/