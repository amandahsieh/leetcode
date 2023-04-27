/*--------------------------Author: Hsin-Yu Hsieh---------------------------*/
/*First Trial: Add & break if <9 OR carry on til [0]  T:0 100%   M:8.9 17.1%*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int finished = 0;
        int which = digits.size()-1;
        while (!finished){
            if (digits[which]<9){
                digits[which] +=1;
                finished = 1;
            }  
            else{
                if (which ==0)  break;
                else    digits[which--] = 0; 
            }
        }
        if (!finished){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};