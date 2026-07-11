class Solution {
    vector<int> vis;
    vector<int> indegree;

    void dfs(unordered_map<int, vector<int>> &adj, int i, int &count) {
        vis[i] = 1;
        count++;

        for (auto k : adj[i]) {
           
            if (!vis[k]) {
                 indegree[k]++;  
                dfs(adj, k, count);
            }
            else indegree[k]++;  
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vis.assign(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                indegree.assign(n, 0);

                int count = 0;
                dfs(adj, i, count);

                bool flag = true;

                for (int j = 0; j < n; j++) {
                    if (vis[j] && indegree[j] != 0) {
                        if (indegree[j] != count - 1) {
                            flag = false;
                            break;
                        }
                    }
                }

                if (count == 1) flag = true;

                if (flag) ans++;
            }
        }

        return ans;
    }
};