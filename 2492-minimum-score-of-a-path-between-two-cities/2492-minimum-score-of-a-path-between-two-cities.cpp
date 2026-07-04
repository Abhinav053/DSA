class Solution {
    vector<int> vis;

    int dfs(int n, unordered_map<int,vector<pair<int,int>>>& adj, int node){

        vis[node] = 1;
        int mini = 1e9;

        for(auto &k : adj[node]){

            int next = k.first;
            int dist = k.second;

            mini = min(mini, dist);

            if(!vis[next]){
                mini = min(mini, dfs(n, adj, next));
            }
        }

        return mini;
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int,vector<pair<int,int>>> adj;

        vis.assign(n+1,0);

        for(auto &k : roads){
            int u = k[0];
            int v = k[1];
            int distance = k[2];

            adj[u].push_back({v,distance});
            adj[v].push_back({u,distance});
        }

        return dfs(n, adj, 1);
    }
};