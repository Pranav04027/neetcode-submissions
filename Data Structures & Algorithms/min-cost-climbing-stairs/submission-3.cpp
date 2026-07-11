class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int dpa = 0;
        int dpb = cost[n-1];

        for (int i = n - 2; i >= 0; i--) {
            int curr = cost[i] + min(dpb, dpa);

            dpa = dpb;
            dpb = curr;
        }

        return min(dpa, dpb);
    }
};