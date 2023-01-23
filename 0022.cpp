/*-----------------------------Author: Hsin-Yu Hsieh-----------------------------*/
/*First Trial: Recursion (added: 1.resize  2.while)    T:3 83.55%    M:11.7 74.2%*/

class Solution {
public:
    vector<string> ans;
    int sum=0;
    void g(int open, int close, int target, string s){
        if (open==close && open==target)    ans[sum++]=s;
        if(open < target) g(open+1, close, target, s+"(");
        else{
            while(close++<target) s+=")";
            ans[sum++]=s;
        }
        if(open > close)  g(open, close+1, target, s+")");
    }
    vector<string> generateParenthesis(int n) {
        ans.resize(1430, "");
        g(1, 0, n, "(");
        ans.erase(ans.begin()+sum, ans.end());
        return ans;
    }
};

/*
Recursion + resize
class Solution {
public:
    vector<string> ans;
    int sum=0;
    void g(int open, int close, int target, string s){
        if (open==close && open==target)    ans[sum++]=s;
        if(open < target) g(open+1, close, target, s+"(");
        if(open > close)  g(open, close+1, target, s+")");
    }
    vector<string> generateParenthesis(int n) {
        ans.resize(1430, "");
        g(1, 0, n, "(");
        ans.erase(ans.begin()+sum, ans.end());
        return ans;
    }
};
*/

/*
Recursion
class Solution {
public:
    vector<string> ans;
    void g(int open, int close, int target, string s){
        if (open==close && open==target)    ans.push_back(s);
        if(open < target) g(open+1, close, target, s+"(");
        if(open > close)  g(open, close+1, target, s+")");
    }
    vector<string> generateParenthesis(int n) {
        g(0, 0, n, "");
        return ans;
    }
};
*/