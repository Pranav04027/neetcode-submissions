class Solution {
public:
    int rec(vector<int>& coins, int target, int i, int n,vector<vector<int>>& dp){

        if(target == 0){
            return 1;
        }

        if(i == n){
            return 0;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        int nottake = rec(coins, target, i + 1, n, dp);

        int take = 0;
        if(coins[i] <= target){
            take = rec(coins, target - coins[i], i, n, dp);
        }

        return dp[i][target] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount +1, -1));
        return rec(coins, amount, 0, n, dp);
    }
};