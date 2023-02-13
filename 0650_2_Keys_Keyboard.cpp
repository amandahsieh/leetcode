/*-------------------Author: Hsin-Yu Hsieh-------------------*/
/*First Trial:  Recursive         T:13 55.49%  M:  6   82.79%*/
/*Second Trial: Recursive & dp    T:44 28.80%  M:155.6 14.72%*/
/*Third Trial:  Prime Division    T: 0 100%    M:  6   60.36%*/

class Solution {
public:
    int minSteps(int n) {
        int ans = 0, i;
        for(i=2; i*i<=n; ++i){
            if(n%i==0){
                ans += i;
                n /= i;
                i=1;
            }
        }
        return (n==1)? ans:ans+n;
    }
};

/*
First Trial: Recursive [copy(+2, copy->val, val->val*2), paste(+1, val->val+copy)]
class Solution {
public:
    int ans = 1;
    int num;
    int cal(int val, int n, int copy){
        if(val == n) return 0;
        if(val>n)   return 1000000;
        return min(2+cal(val*2, n, val), 1+cal(val+copy, n, copy));
    }
    int minSteps(int n) {
        return cal(1, n, 1) + (n!=1);
    }
};
*/

/*
Second Trial: calculate st & val & dp
class Solution {
public:
    int cal(int st, int val, int n, int copy, vector<vector<int>>& dp){
        if(val == n) return st;
        if(val>n || st>n)   return INT_MAX;
        if(dp[st][val]!=-1) return dp[st][val];
        dp[st][val] = min(cal(st+1, val+copy, n, copy, dp), cal(st+2, val*2, n, val, dp));
        return dp[st][val];
    }
    int minSteps(int n) {
        if(n==1)    return 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return cal(1, 1, n, 1, dp);
    }
};
*/