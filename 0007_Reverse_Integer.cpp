class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        int l = pow(2,31)*-1;
        int u = pow(2,31)-1;
        int neg = (x<0)? -1:1;
        x = abs(x);
        while (x>0){
            ans = ans*10 + x%10;
            if (ans>u || ans<l){
                ans=0;
                break;
            }
            x/=10;
        }
        return ans * neg;
    }
};
