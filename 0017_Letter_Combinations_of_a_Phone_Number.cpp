/*-----------------------------Author: Hsin-Yu Hsieh-----------------------------*/
/*First Trial: backtracking digits, di, mapi, string   T:2 46.33%    M:6.5 81.59%*/
/*Second Trial: backtracking digits, di, string        T:0 100%      M:6.6 53.76%*/
/*Third Trial:  backtracking digits, di, string, mp    T:0 100%      M:6.4 94.36%*/
class Solution {
public:
    vector<string> ans;
    void add(string d, int si, string tmp, string mp[]){
        if(si==d.length())    ans.push_back(tmp);
        else{
            for(int j=0; j<mp[d[si]-'2'].length(); j++) add(d, si+1, tmp+mp[d[si]-'2'][j], mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.length())    return ans;
        string mp[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        add(digits, 0, "", mp);
        return ans;
    }
};

/*
First Trial: 
class Solution {
public:
    vector<string> ans;
    vector<string> mp;
    void add(string d, int si, int mi, string tmp){
        tmp = tmp + mp[d[si]-'2'][mi];
        if(si==d.length()-1)    ans.push_back(tmp);
        else{
            for(int j=0; j<mp[d[si+1]-'2'].length(); j++)    add(d, si+1, j, tmp);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.length())    return ans;
        mp.resize(8);
        mp[0] = "abc";
        mp[1] = "def";
        mp[2] = "ghi";
        mp[3] = "jkl";
        mp[4] = "mno";
        mp[5] = "pqrs";
        mp[6] = "tuv";
        mp[7] = "wxyz";
        for(int i=0; i<mp[digits[0]-'2'].length(); i++)    add(digits, 0, i, "");
        return ans;
    }
};
*/

/*
Second Trial: 
class Solution {
public:
    vector<string> ans;
    vector<string> mp;
    void add(string d, int si, string tmp){
        if(si==d.length())    ans.push_back(tmp);
        else{
            for(int j=0; j<mp[d[si]-'2'].length(); j++)   add(d, si+1, tmp+mp[d[si]-'2'][j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.length())    return ans;
        mp.resize(8);
        mp[0] = "abc";
        mp[1] = "def";
        mp[2] = "ghi";
        mp[3] = "jkl";
        mp[4] = "mno";
        mp[5] = "pqrs";
        mp[6] = "tuv";
        mp[7] = "wxyz";
        add(digits, 0, "");
        return ans;
    }
};
*/