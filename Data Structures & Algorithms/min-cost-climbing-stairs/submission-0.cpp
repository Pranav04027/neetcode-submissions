class Solution {
public:
int rec(vector<int>& cost, int i, int n, vector<int> & dp){
    if(i >= n){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    return dp[i] = cost[i] + min(rec(cost, i+1,n, dp), rec(cost, i+2, n, dp));
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp (n+1,-1);
        dp[n] = 0;
        dp[n-1] = cost[n-1];

        return min (rec(cost, 0, n, dp), rec(cost, 1,n, dp));
    }
};
