class Solution {
public:
    bool rec(vector<int> &nums, int target, int i, int n, vector<vector<int>>& dp) {

        if (target == 0) return true;

        if (i == n - 1) return nums[n - 1] == target;
        
        if (dp[i][target] != -1){
            return dp[i][target];
        }

        bool nottake = rec(nums, target, i + 1, n, dp);

        bool take = false;

        if (nums[i] <= target) {
            take = rec(nums, target - nums[i], i + 1, n, dp);
        }

        return dp[i][target] = take || nottake; // t become 1, false become 0 yayay
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int it:nums){
            sum += it;
        }

        if(sum %2 == 1){
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        return rec(nums, sum/2, 0, n, dp);
    }
};