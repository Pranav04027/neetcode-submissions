class Solution {
public:
    int rec (string &text1, string &text2, int i, int j, int n, int m,vector<vector<int>>& dp){
        if(i==n || j== m){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + rec(text1, text2, i+1, j+1, n, m, dp);
        }

        return dp[i][j] = 0 + max(rec(text1, text2, i+1, j, n, m, dp), rec(text1, text2, i, j+1, n, m, dp));

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return rec(text1, text2, 0, 0, n, m, dp);

    }
};