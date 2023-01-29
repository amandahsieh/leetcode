/*----------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: Record #used characters   T:6 89.44%  M:7.1 97.56%*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        vector<int> s1(26);
        vector<int> s2(26);
        for (int i=0 ; i<s.size() ; i++){
            s1[s[i]-'a']++;
            s2[t[i]-'a']++;
        }
        for (int i=0 ; i<26 ; i++){
            if (s1[i]!=s2[i])   return false;
        }
        return true;
    }
};