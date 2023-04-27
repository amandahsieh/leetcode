/*---------------------Author: Hsin-Yu Hsieh----------------------*/
/*First Trial: Recursive & count         T:0 100%     M:6.4 88.91%*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)    return "1";
        int cnt=1, i;
        string s = countAndSay(n-1);
        string ans="";
        for(i=1; i<s.size(); i++){
            if(s[i]==s[i-1])    cnt++;
            else{
                ans += cnt+'0';
                ans += s[i-1];
                cnt=1;
            }
        }
        if(cnt){
            ans += cnt+'0';
            ans += s[i-1];
        }
        return ans;
    }
};