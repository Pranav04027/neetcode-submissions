class Solution {
private:
    bool detectcycle(int n,  vector<int>& visited, vector<vector<int>>& adj, int i){
        visited[i] = 1;
        queue<pair<int,int>> q;
        q.push({i, -1});

        while(!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(auto node : adj[curr]){
                if(visited[node] == 0){
                    visited[node] = 1;
                    q.push({node, curr});
                }else if(node != parent){
                    return true;
                }
            }

        }

        return false;

    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Make adj list;
        vector<vector<int>> adj(n);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //visited arr
        vector<int> visited(n,0);

        int count = 0;

        bool cycle = false;

        for(int i = 0; i< n; i++){
            if(visited[i] == 0){
                count++;
                cycle = detectcycle(n, visited, adj, i);
            }
        }

        return (count == 1) && !cycle;


    }
};
