class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int current = 0;
        int maxm = 0;

        for (auto & it: st) {

            if (st.find(it - 1) == st.end()) {
                int temp = it;
                while (st.find(temp) != st.end()) {
                    current++;
                    temp++;
                }
                maxm = max(maxm, current);

                current = 0;
            }
        }

        return maxm;
    };
};