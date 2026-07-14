class Solution {
public:

    int rec(vector<int> & nums, int i , int n, int findt, vector<vector<int>>& dp){
        if(i == n){
            if(findt == 0){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][findt] != -1){
            return dp[i][findt];
        }

        int nottake = rec(nums, i+1, n, findt, dp);

        int take = 0;

        if(nums[i] <= findt){
            take = rec(nums, i+1, n, findt-nums[i], dp);
        }

        return dp[i][findt] = take + nottake;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(auto it: nums){
            sum += it;
        }

        if (abs(target) > sum) return 0;

        int realt = sum + target;

        if(realt < 0 || realt %2 == 1){
            return 0;
        }

        int findt = realt/2;

        vector<vector<int>> dp (n, vector<int> (findt+1, -1));

        return rec(nums, 0, n, findt, dp);
        

    }
};