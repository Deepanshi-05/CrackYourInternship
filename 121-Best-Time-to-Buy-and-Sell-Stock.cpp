class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[buy]){
              prices[buy] = prices[i];
            }
            else if(prices[i] > prices[buy]){
               int profit = prices[i] - prices[buy];
               maxProfit = max(maxProfit,profit);
            }

        }
        return maxProfit;
    }
};