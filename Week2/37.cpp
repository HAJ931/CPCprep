class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, minPrice = prices[0];
        for(int i = 0; i < prices.size(); ++i){
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else if(max_profit < prices[i] - minPrice)
                max_profit = prices[i] - minPrice;
        }
        return max_profit;
    }
};
