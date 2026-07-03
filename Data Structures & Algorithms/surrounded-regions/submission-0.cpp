class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<int>>& visited,
             pair<int, int> node) {

        int m = board.size();
        int n = board[0].size();

        bool border = false;

        queue<pair<int, int>> q;
        vector<pair<int, int>> cells;

        q.push(node);
        visited[node.first][node.second] = 1;

        while (!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            cells.push_back({i, j});

            if(i==0 || j==0 || i==m-1 || j==n-1)
                border = true;

            int dr[4] = {-1,1,0,0};
            int dc[4] = {0,0,-1,1};

            for(int k=0;k<4;k++){

                int ni = i + dr[k];
                int nj = j + dc[k];

                if(ni>=0 && nj>=0 && ni<m && nj<n &&
                   !visited[ni][nj] && board[ni][nj]=='O'){

                    visited[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }

        // after BFS ends
        if(!border){
            for(auto [i,j] : cells){
                board[i][j]='X';
            }
        }
    }


    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(!visited[i][j] && board[i][j]=='O'){
                    bfs(board, visited, {i,j});
                }

            }
        }
    }
};