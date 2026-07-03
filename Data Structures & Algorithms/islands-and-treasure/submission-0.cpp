class Solution {
public:
    const int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            if(i-1 >= 0 && grid[i-1][j] == INF){
                grid[i-1][j] = distance+1;
                q.push({{i-1,j},distance+1});
            }

            if(i+1 < m && grid[i+1][j] == INF){
                grid[i+1][j] = distance+1;
                q.push({{i+1,j},distance+1});
            }

            if(j-1 >= 0 && grid[i][j-1] == INF){
                grid[i][j-1] = distance+1;
                q.push({{i,j-1},distance+1});
            }

            if(j+1 < n && grid[i][j+1] == INF){
                grid[i][j+1] = distance+1;
                q.push({{i,j+1},distance+1});
            }
        }
    }
};