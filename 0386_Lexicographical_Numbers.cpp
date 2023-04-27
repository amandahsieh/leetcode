/*----------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: Recursive cal            T:3 98.88%  M:10.8 86.19%*/

class Solution {
public:
    int cnt = 0;
    vector<int> ans;
    void cal(int num, int n){
        num *= 10;
        for(int i=0; i<10; i++){
            if(num+i==0)    continue;
            if(num+i>n) break;
            ans[cnt++] = num+i;
            cal(num+i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        ans.resize(n);
        cal(0, n);
        return ans;
    }
};