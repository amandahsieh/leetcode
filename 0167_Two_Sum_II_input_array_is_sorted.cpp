/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: 2 Pointers           T:8 95.79%    M:15.7 50.45%*/
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