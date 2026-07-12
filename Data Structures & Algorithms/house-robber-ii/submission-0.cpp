class Solution {
public:
    int rec(vector<int> &nums, int n, int i, vector<int>& dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int first = rec(nums, n, i+1, dp);

        int second = nums[i] + rec(nums, n, i+2, dp);

        return dp[i] = max(first, second);

    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp(n, -1);

        int nofirst = rec(nums, n, 1, dp);
        dp.assign(n, -1);
        int nosecond = rec(nums,n-1, 0, dp);

        return max(nofirst, nosecond);
    }
};