/*----------------------Author: Hsin-Yu Hsieh-----------------------*/
/*First Trial: min(walls) & bottom     T:17 72.81%     M:20.6 11.18%*/
/*Second Trial: two pointers + max l r T:14 87.68%     M:19.7 85.35%*/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int ml = height[0], mr = height[height.size()-1];
        int i=0, j=height.size()-1;
        while(i<j){
            int tmp;
            if(ml<=mr){
                i++;
                ml = max(ml, height[i]);
                ans += ml - height[i];
            }
            else if (ml>mr){
                j--;
                mr = max(mr, height[j]);
                ans += mr - height[j];
            }
        }
        return ans;
    }
};

/*
First Trial
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        vector<int> ml(height.size());
        vector<int> mr(height.size());
        for(int i=1; i<height.size(); i++)    ml[i]=max(ml[i-1], height[i-1]);
        for(int i=height.size()-2; i>=0; i--)    mr[i]=max(mr[i+1], height[i+1]);
        for(int i=0; i<height.size(); i++){
            int tmp = min(ml[i], mr[i])-height[i];
            if (tmp>0)    ans+=tmp;
        }
        return ans;
    }
};
*/