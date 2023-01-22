/*-------------------------Author: Hsin-Yu Hsieh-------------------------*/
/*First Trial: check each end & biggest begin  T:130 11.29%  M:8.3 20.60%*/
/*Second Trial: satisfied begin++ OR ends++    T:6   97.5 %  M:8.1 47.34%*/

class Solution {
public:
    string minWindow(string s, string t) {
        int b=0, e=0, have=0, need=0, begin=0, ends=-1;
        vector<int> cnt(58);
        vector<int> anscnt(58);
        for(int i=0; i<t.size(); i++){
            anscnt[t[i]-'A']++;
            if(anscnt[t[i]-'A']==1)need++;
        }
        while(e<=s.size() && b<=s.size()){
            if(have == need){
                if(ends-begin+1<=0 || (ends-begin>=e-b)){
                    begin = b;
                    ends = e-1;
                }
                cnt[s[b]-'A']--;
                if(cnt[s[b]-'A']<anscnt[s[b]-'A'])    have--;
                b++;
            }
            else {
                if(e<s.size()){
                    cnt[s[e]-'A']++;
                    if(cnt[s[e]-'A']==anscnt[s[e]-'A']) have++;
                }
                e++;
            }
        }
        return s.substr(begin, ends-begin+1);
    }
};

/*
First Trial
class Solution {
public:
    string minWindow(string s, string t) {
        int b=0, e, n=1,f=0;
        string ans="";
        vector<int> cnt(58);
        vector<int> anscnt(58);
        for(int i=0; i<t.size(); i++)   anscnt[t[i]-'A']++;
        for(e=0; e<s.size(); e++){
            cnt[s[e]-'A']++;
            int c;
            for(c=0; c<58; c++)    if(cnt[c]<anscnt[c])    break;
            if (c<58)    continue;
            while(b<=e){
                if(cnt[s[b]-'A']-1<anscnt[s[b]-'A'])    break;
                cnt[s[b++]-'A']--;
            }
            //cout << b << " "<<e<<endl;
            if (ans.size()==0 || ans.size()>e-b+1)  ans = s.substr(b, e-b+1);
        }
        return ans;
    }
};
*/