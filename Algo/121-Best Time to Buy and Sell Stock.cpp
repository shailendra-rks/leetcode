class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int max = 0;
        for(int price : prices){
            if(buy > price){
                buy = price;
                sell = price;
            }
            if(sell < price){
                sell = price;
                max = max < sell-buy ? sell-buy : max;
            }
        }
        return max;
    }
};