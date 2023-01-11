class Solution {
public:
    int climbStairs(int n) {
        vector<int> num(2,1);
        for (int i=2 ; i<=n ; i++){
            swap(num[0], num[1]);
            num[1]+=num[0];
        }
        return num[1];
    }
};