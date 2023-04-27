/*---------------------Author: Hsin-Yu Hsieh---------------------*/
/*First Trial: m2, m3, m5  (dp)          T:3 97.67%  M:7.6 72.41%*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n);
        nums[0]=1;
        int m2=0, m3=0, m5=0, cnt=1;
        int tmp2, tmp3, tmp5;
        while(cnt<n){
            tmp2 = nums[m2]*2;
            tmp3 = nums[m3]*3;
            tmp5 = nums[m5]*5;
            if     (tmp2< tmp3 && tmp2< tmp5)  {nums[cnt++]=tmp2; m2++;}
            else if(tmp2==tmp3 && tmp3< tmp5)  {nums[cnt++]=tmp2; m2++; m3++;}
            else if(tmp2< tmp3 && tmp3==tmp5)  {nums[cnt++]=tmp2; m2++; m5++;}
            else if(tmp2==tmp3 && tmp3==tmp5)  {nums[cnt++]=tmp2; m2++; m3++; m5++;}
            else if(tmp3< tmp2 && tmp3< tmp5)  {nums[cnt++]=tmp3; m3++;}
            else if(tmp3==tmp2 && tmp3< tmp5)  {nums[cnt++]=tmp3; m3++; m2++;}
            else if(tmp3< tmp2 && tmp3==tmp5)  {nums[cnt++]=tmp3; m3++; m5++;}
            else if(tmp3==tmp2 && tmp3==tmp5)  {nums[cnt++]=tmp3; m3++; m2++; m5++;}
            else if(tmp5< tmp2 && tmp5< tmp3)  {nums[cnt++]=tmp5; m5++;}
            else if(tmp5==tmp2 && tmp5< tmp3)  {nums[cnt++]=tmp5; m5++; m2++;}
            else if(tmp5< tmp2 && tmp5==tmp3)  {nums[cnt++]=tmp5; m5++; m3++;}
            else if(tmp5==tmp2 && tmp5==tmp3)  {nums[cnt++]=tmp5; m5++; m2++; m3++;}
        }
        return nums[n-1];
    }
};