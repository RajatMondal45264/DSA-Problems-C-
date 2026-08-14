class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy_Price = prices[0];

        for(int i = 1;i<n ; i++)
        {
            int curr_Profit = prices[i] - buy_Price;
            if(curr_Profit > maxProfit)
            {
                maxProfit = curr_Profit;
            }

            if(prices[i] < buy_Price)
            {
                buy_Price = prices[i];
            }
        }

        return maxProfit;
    }
};