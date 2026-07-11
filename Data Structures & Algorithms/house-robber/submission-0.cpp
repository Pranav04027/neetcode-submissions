class Solution {
public:
    // rec (i) == Max sum i can get from 0 to i
    int rec(vector<int>& dp, vector<int> & nums, int n, int i){
        if(i == 0){
            return nums[0];
        }

        if(i<0){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int take = nums[i] + rec(dp, nums, n, i-2);

        int nottake = rec(dp, nums, n ,i-1);

        return dp[i] = max(take, nottake);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return rec(dp, nums, n, n-1);

    }
};
