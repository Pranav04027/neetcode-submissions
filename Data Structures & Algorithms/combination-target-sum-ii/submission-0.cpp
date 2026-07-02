class Solution {
public:
    void recursion(vector<int>& candidates, int target, int index,
                   vector<int>& temp, int sum,
                   vector<vector<int>>& ans) {

        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (sum + candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);

            recursion(candidates,
                      target,
                      i + 1,
                      temp,
                      sum + candidates[i],
                      ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        recursion(candidates, target, 0, temp, 0, ans);

        return ans;
    }
};