/*------------------------Author: Hsin-Yu Hsieh------------------------*/
/*First Trial: vector, compare, vector to int   T:6 8.47%  M:6   69.98%*/
/*Second Trial: last digit, compare, pow        T:0 100%   M:6.2  5.74%*/

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int last = 10, p = 0, ans = n, s=0;
        while(n){
            if(n%10 > last){
                ans = (n--)*pow(10, p)-1;
                s = p;
            }
            last = n%10;
            n/=10;
            p++;
        }
        return ans;
    }
};

/*
First Trial: vector, compare, vector to int
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> digits(10);
        int tmp = 9, start = 10, ans=0;
        while(n){
            digits[tmp--] = n%10;
            n/=10;
        }
        for(tmp = 0; tmp<10; tmp++) cout << digits[tmp];
        cout << endl;
        for(tmp = 9; tmp>0; tmp--){
            if(digits[tmp]<digits[tmp-1]){
                start = tmp;
                digits[tmp-1]--;
            }
        }
        for(tmp=0; tmp<start; tmp++){
            ans *= 10;
            ans += digits[tmp];
        }
        for(tmp=start; tmp<10; tmp++){
            ans *= 10;
            ans += 9;
        }
        return ans;
    }
};
/* 3238 */
*/