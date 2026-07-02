class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i< n; i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> freq(n+1); //by default init with 0

        for(auto &x : mp){
            freq[x.second].push_back(x.first);
        }

        vector<int> ans;

        for(int i = freq.size() - 1; i>0; i--){

            for(int j = 0; j<freq[i].size(); j++){
                ans.push_back(freq[i][j]);
            }
            if(ans.size() == k){
                return ans;
            }
        }

        return ans;

    }
};