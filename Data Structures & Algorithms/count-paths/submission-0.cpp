class Solution {
public:
    int rec(int m, int n, int i, int j, vector<vector<int>> & dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j>=n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = rec(m,n, i, j+1, dp);
        int down = rec(m,n, i+1, j, dp);

        return dp[i][j] = right + down;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return rec(m,n,0,0, dp);
    }
};