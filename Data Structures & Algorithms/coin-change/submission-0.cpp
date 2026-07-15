class Solution {
public:
    int rec(vector<int>& coins, int target, int i, int n, vector<vector<int>> &dp) {

        if (i == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        int nottake = rec(coins, target, i - 1, n, dp);

        int take = 1e9;
        if (coins[i] <= target) {
            take = 1 + rec(coins, target - coins[i], i, n, dp);
        }

        return dp[i][target] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = rec(coins, amount, n - 1, n, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};