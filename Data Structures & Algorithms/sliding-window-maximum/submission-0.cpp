class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            while(!dq.empty() && dq.back().first <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        }

        ans.push_back(dq.front().first);

        int l = 0;

        for(int r = k; r < nums.size(); r++) {

            while(!dq.empty() && dq.back().first <= nums[r]) {
                dq.pop_back();
            }
            dq.push_back({nums[r], r});

            if(dq.front().second == l) {
                dq.pop_front();
            }

            l++;

            ans.push_back(dq.front().first);
        }

        return ans;
    }
};