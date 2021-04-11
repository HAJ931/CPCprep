class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = prices[0], secondBuy = prices[0], profit1 = 0, finalProfit = 0;
        for (int i = 0; i < prices.size(); ++i){
            firstBuy = firstBuy < prices[i] ? firstBuy : prices[i];
            profit1 = profit1 > prices[i] - firstBuy ? profit1 : prices[i] - firstBuy;
            secondBuy = secondBuy < prices[i] - profit1 ? secondBuy : prices[i] - profit1;
            finalProfit = finalProfit > prices[i] - secondBuy ? finalProfit: prices[i] - secondBuy;
        } 
        return finalProfit;
    }
};
