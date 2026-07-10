class Solution {
public:
/*
    int count(int n, int i, vector<int> & dp){
        if(i == n){
            return 1;
        }
        if(i > n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }

        int l = count(n, i+1, dp);

        int r = count(n, i+2, dp);

        return dp[i] = l + r;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return count(n,0, dp);
    }
    */


    int climbStairs(int n) {

        vector<int> dp(n+2, 0);

        dp[n] = 1;

        for(int i = n-1; i >= 0; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }

        return dp[0];
    }


};
