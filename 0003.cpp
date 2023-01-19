/*--------------------------Author: Hsin-Yu Hsieh--------------------------*/
/*First Trial: Used -> new start, new substring   T:7 93.87%   M:6.9 92.25%*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)  return 0;
        int len = 1, start = 0;
        int used[150] = {0};
        for (int i=0 ; i<s.size() ; i++){
            for (int j=start ; j<s.size() ; j++){
                if (used[s[j]] == 1){
                    len = max(len, j - i);
                    start = j;
                    used[s[i]] = 0;
                    break;
                }    
                else{
                    used[s[j]] = 1;
                    if (j == s.size()-1)    len = max(len, j-i+1);
                }
            }
        }
        return len;
    }
};