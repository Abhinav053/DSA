class Solution {
    vector<int> disc, low;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        disc[node] = low[node] = timer++;

        for (int nei : adj[node]) {
            if (nei == parent)
                continue;

            if (disc[nei] == -1) {
                dfs(nei, node, adj);

                low[node] = min(low[node], low[nei]);

                if (low[nei] > disc[node]) {
                    ans.push_back({node, nei});
                }
            } else {
                low[node] = min(low[node], disc[nei]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        disc.assign(n, -1);
        low.assign(n, -1);

        dfs(0, -1, adj);

        return ans;
    }
};