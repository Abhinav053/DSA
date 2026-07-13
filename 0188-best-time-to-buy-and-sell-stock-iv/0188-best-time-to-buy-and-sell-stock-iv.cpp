class Solution {
    int profitmax(vector<int>& prices, int i, int canBuy, int k, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || k == 0) return 0;

        if (dp[i][canBuy][k] != -1) return dp[i][canBuy][k];

        int profit = 0;
        if (canBuy) {
            // Buy or skip
            profit = max(-prices[i] + profitmax(prices, i + 1, 0, k, dp),
                          profitmax(prices, i + 1, 1, k, dp));
        } else {
            // Sell or skip
            profit = max(prices[i] + profitmax(prices, i + 1, 1, k - 1, dp),
                          profitmax(prices, i + 1, 0, k, dp));
        }

        return dp[i][canBuy][k] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(k + 1, -1)));

        return profitmax(prices, 0, 1, k, dp); 
    }
};