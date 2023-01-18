class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        long long int m = pow(2,31);
        int pn = 0;
        int lead = 0;
        for (int i=0 ; i<s.size() ; i++){
            if (lead && (s[i]>'9' || s[i]<'0'))   break;
            if (s[i]==' ' && pn==0) continue;
            if (pn==0 && s[i]=='-')  pn = -1;
            else if (pn==0 && s[i]=='+') pn = 1;
            else if (s[i]>='0' && s[i]<='9'){
                lead = 1;
                ans *= 10;
                ans += s[i]-'0';
                if (ans>m)  ans = m;
            }
            else    break;
        }
        if (pn!=0)    ans *= pn;
        if (ans<0 && ans < -1*m)     ans = -1*m;
        else if (ans>0 && ans > m-1) ans = m-1;
        return ans;
    }
};