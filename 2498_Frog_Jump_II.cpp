/*--------------------------Author: Hsin-Yu Hsieh--------------------------*/
/*First Trial: Greedy, leaving one for return   T:137 98.30%  M:65.3 68.56%*/

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int m = 0, i, to, n=stones.size();
        for(i=0; i<n; i++){
            if(i+2>=n){
                m = max(m, stones[n-1]-stones[i]);
                break;
            }
            m = max(m, stones[i+2]-stones[i]);
        }
        return m;
    }
};