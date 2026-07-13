class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int prevMax = currMax;
            int prevMin = currMin;

            currMax = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
            currMin = min({nums[i], prevMax * nums[i], prevMin * nums[i]});

            ans = max(ans, currMax);
        }

        return ans;
    }
};