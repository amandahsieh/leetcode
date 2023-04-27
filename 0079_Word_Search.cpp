/*------------------------Author: Hsin-Yu Hsieh-----------------------*/
/*First Trial: DFS & Prune[size cnt prefix]  T:28 98.75%  M:25.6 5.52%*/

//Without Prune -> TLE
class Solution {
public:
    int m, n, l, i, j;
    bool check(vector<vector<char>> b, int x, int y, string w, int idx){
        if(x>=m || y>=n || x<0 || y<0 || b[x][y]!=w[idx]) return false;
        b[x][y] = '_';
        if(++idx==l) return true;
        return  check(b, x-1, y, w, idx)||check(b, x+1, y, w, idx)||check(b, x, y-1, w, idx)||check(b, x, y+1, w, idx);
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.size();
        //Prune1: Size
        if(l>m*n)   return false;
        //Prune2: Count
        unordered_map<char, int> mp;
        for(i=0; i<m; i++){
            for(j=0; j<n; j++)  mp[board[i][j]]++;
        }
        for(i=0; i<l; i++)  if(--mp[word[i]]<0) return false;
        //Prune3: Prefix & Suffix
        if (word.find_first_not_of(word[0]) > l - word.find_last_not_of(word[l - 1])) reverse(begin(word), end(word));

        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                if(check(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};