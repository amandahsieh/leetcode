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