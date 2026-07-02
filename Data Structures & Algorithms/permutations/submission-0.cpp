class Solution {
public:
    void recursion (vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& selected){
        if(temp.size()== nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i< selected.size(); i++){
            if(selected[i] == false){
                temp.push_back(nums[i]);
                selected[i] = true;
                recursion(nums, ans, temp, selected);
                temp.pop_back();
                selected[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<bool> selected(n,false);
        recursion(nums, ans, temp, selected);
        return ans;
    }
};