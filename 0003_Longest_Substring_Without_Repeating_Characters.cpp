/*--------------------------Author: Hsin-Yu Hsieh--------------------------*/
/*First Trial: Used -> new start, new substring     T:0 100%   M:6.8 99.61%*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        int l=s.size(), i, j;
        if (!l)  return 0;
        int len = 1, start = 0;
        int used[128] = {0};
        for (i=0 ; i<l ; i++){
            for (j=start ; j<l ; j++){
                if (used[s[j]]){
                    len = (len>j-i)? len:j-i;
                    start = j;
                    used[s[i]] = 0;
                    break;
                }
                used[s[j]] = 1;
                if (j == l-1)    len = (len>j-i+1)? len:j-i+1;
            }
        }
        return len;
    }
};