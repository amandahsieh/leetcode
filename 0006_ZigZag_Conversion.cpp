class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        int n = numRows*2 -2;
        int t = 0;
        vector <string> tmp(numRows);
        for (int i=0 ; i<s.size() ; i++){
            if (t < numRows)    tmp[t++] += s[i];
            else if (t < n)     tmp[n-(t++)] += s[i];
            if (t==n)           t=0;
        }
        string ans;
        for (int i=0 ; i<numRows ; i++) ans+=tmp[i];
        return ans;
    }
};