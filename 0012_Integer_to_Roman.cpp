/*------------------Author: Hsin-Yu Hsieh------------------*/
/*First Trial: num & roman string    T:3 94.38%  M:6 79.46%*/
class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        int i=0;
        int nums[13]=    {1000, 900, 500, 400,  100,  90,  50,   40,  10,   9,    5,   4,    1};
        string roman[13]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        while(num){
            while(num>=nums[i]){
                ans += roman[i];
                num -= nums[i];
            }
            i++;
        }
        return ans;
    }
};

/*
class Solution {
public:
    string intToRoman(int num) {
        string ones[]  =     {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[]  =     {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] =  {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] =  {"", "M", "MM", "MMM"};
        return thousands[num/1000]+hundreds[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
    }
};
*/