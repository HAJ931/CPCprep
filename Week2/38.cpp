class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, maxprof = 0, valley = prices[0], peak = prices[0];
        while(i < prices.size() - 1){
             while(i < prices.size() - 1 && prices[i] >= prices[i + 1])
                ++i;
            //Found the first valley/dip in price
            valley = prices[i];
            while(i < prices.size() - 1 && prices[i] <= prices[i + 1])
                ++i;
            //Found the peak closest to the above valley
            peak = prices[i];
            maxprof += peak - valley;
        }
        return maxprof;
    }
};
