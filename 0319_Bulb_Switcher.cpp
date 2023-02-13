/*-------------Author: Hsin-Yu Hsieh-------------*/
/*First:  Math Solution     T:0 100%  M:6  10.7% */

class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1)    return n;
        return sqrt(n);
    }
};