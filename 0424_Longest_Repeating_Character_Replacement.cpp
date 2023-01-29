/*----------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: used char&sliding window    T:6 90.59%  M:7 86.13%*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int e, b=0, a=0, m=0;
        vector<int> cnt(26);
        for(e=0; e<s.size(); e++){
            m = max(m, ++cnt[s[e]-'A']);
            if(e-b+1-m>k)     cnt[s[b++]-'A']--;
            else    a = max(a, e-b+1);
        }
        return a;
    }
};