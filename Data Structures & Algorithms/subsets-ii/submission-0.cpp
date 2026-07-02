class Solution {
public:
    void recursion(vector<int>& nums, vector<vector<int>>& ans,
                   vector<int>& temp, int start) {
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            temp.push_back(nums[i]);

            recursion(nums, ans, temp, i + 1);

            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        recursion(nums, ans, temp, 0);

        return ans;
    }
};