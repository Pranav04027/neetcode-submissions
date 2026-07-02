class Solution {
public:
    void bfs(vector<vector<char>>& grid, pair<int,int> node, vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        visited[node.first][node.second] = 1;
        q.push(node);

        while(!q.empty()){
            pair<int,int> currnode = q.front();
            int i = currnode.first;
            int j = currnode.second;

            q.pop();

            // top
            if((i-1)>=0 && grid[i-1][j] =='1' && visited[i-1][j] == 0){
                visited[i-1][j] = 1;
                q.push({i-1, j});
            }

            //left
            if((j-1)>=0 && grid[i][j-1] =='1' && visited[i][j-1] == 0){
                visited[i][j-1] = 1;
                q.push({i, j-1});
            }

            //bottom
            if((i+1)<m && grid[i+1][j] == '1' && visited[i+1][j] == 0){
                visited[i+1][j] = 1;
                q.push({i+1, j});
            }

            //right
            if((j+1)<n && grid[i][j+1] =='1' && visited[i][j+1] == 0){
                visited[i][j+1] = 1;
                q.push({i, j+1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));
        int ans = 0;

        for(int i = 0; i< m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]== '1' && visited[i][j]==0){
                    bfs(grid, {i,j}, visited);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};