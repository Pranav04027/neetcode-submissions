class Solution {
public:
    // rec(i, prev)  -> denotes the maximum length of LIS fron i to last
    int rec(vector<int>& nums, int i, int prev, int n, vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }

        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }

        int nottake = rec(nums, i+1, prev, n, dp);

        int take = 0;
        if(prev == -1 || nums[i]>nums[prev]){
            take = 1 + rec(nums, i+1, i, n, dp);
        }

        int ans = max(take, nottake);

        if(prev != -1)
            dp[i][prev] = ans;

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(nums, 0, -1, n, dp);
    }
};