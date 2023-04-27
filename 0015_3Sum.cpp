/*---------------------Author: Hsin-Yu Hsieh---------------------*/
/*First Trial: for loop + 2 Pointers  T:134 60.76%  M:24.1 27.57%*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(i<j){
            int tmp = numbers[i]+numbers[j];
            if(tmp>target)  j--;
            else if (tmp<target)    i++;
            else    return {i+1, j+1};
        }
        return {i+1, j+1};
    }
};