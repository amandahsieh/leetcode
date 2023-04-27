/*-----------------------Author: Hsin-Yu Hsieh-----------------------*/
/*First Trial:  Buy & Sell's best time      T:3 96.80%  M:13.1 64.48%*/
/*Second Trial: Buy & Sell when profit      T:3 96.80%  M:13.1 64.48%*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, tmp, i;
        for(i=1; i<prices.size(); i++){
            tmp = prices[i]-prices[i-1];
            ans = (tmp>0)? ans+tmp:ans;
        }
        return ans;
    }
};

/*
First Trial: Buy & Sell's Best Time
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell, ans = 0;
        bool epty = 1;
        for(int i=1; i<prices.size(); i++){
            if(epty){
                if(buy>prices[i])   buy = prices[i];
                else{
                    epty = 0;
                    sell = prices[i];
                }
            }
            else{
                if(sell<prices[i])  sell = prices[i];
                else{
                    epty = 1;
                    ans += sell-buy;
                    buy = prices[i];
                    sell = 0;
                }
            }
        }
        return (sell && !epty)? ans+sell-buy:ans;
    }
};
*/