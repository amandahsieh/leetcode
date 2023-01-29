/*----------------------------Author: Hsin-Yu Hsieh---------------------------*/
/*First Trial: Check each left bound and right bound   T:2061 5%  M:59.4 5.3% */
/*Second Trial: Two Pointers                         T:92 90.67%  M:59.1 5.12%*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int ans = 0;
        while (j>i){
            int tmp = min(height[i], height[j]);
            ans = max(ans, (j-i)*tmp);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        long long int ans = 0;
        for (i=0 ; i<height.size() ; i++){
            int j=height.size()-1;
            while (j>i){
                long long int tmp = min(height[i], height[j]);
                ans = max(ans, (j-i)*tmp);
                if (height[i]<height[j])    break;
                j--;
                if (height[i]<height[j+1]&&height[j]<=height[j+1]){
                    while (height[j]<=height[j+1] && j>i)   j--;
                }
            }
        }
        return ans;
    }
};
*/