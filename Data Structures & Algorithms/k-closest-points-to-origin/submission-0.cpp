class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> heap;

        for(int i = 0; i< points.size(); i++){
           long long distance = 1LL * points[i][0] * points[i][0] + 1LL * points[i][1] * points[i][1];
           heap.push({distance, i});

           if(heap.size()>k){
                heap.pop();
           }
        }

        vector<vector<int>> ans;

        while(heap.size()){
            ans.push_back(points[heap.top().second]);
            heap.pop();
        }
        return ans;
    }
};