class Solution {
public:
    void bfs(int n, vector<vector<int>>& adj,vector<int>& visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it: adj[curr]){
                if(visited[it] == 0){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited (n,0);
        int count = 0;

        vector<vector<int>> adj(n);

        for(int i = 0; i< edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i<n; i++){
            if(visited[i] == 0){
                count++;
                bfs(n,adj,visited,i);
            }
        }

        return count;
    }
};
