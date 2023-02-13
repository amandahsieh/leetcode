/*----------------------Author: Hsin-Yu Hsieh-----------------------*/
/*First Trial: vector then string                T:0 100%  M:6.8 65%*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size(), n2=num2.size();
        int l=n1+n2, i, j, tmp;
        vector<int> digits(l, 0);
        string ans(l, '0');
        for(i=n1-1; i>=0; i--){
            for(j=n2-1; j>=0; j--)  digits[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
        }
        for(i=l-1; i>0; i--){
            digits[i-1]+=digits[i]/10;
            ans[i]+=(digits[i]%=10);
        }
        ans[0]+=digits[0];
        for(i=0; i<l-1; i++)    if(ans[i]!='0') break;
        return ans.substr(i);
    }
};