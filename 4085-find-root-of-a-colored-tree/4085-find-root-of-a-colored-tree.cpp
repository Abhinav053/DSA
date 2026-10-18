class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();

        vector<int> degree(n, 0), indegree(n, 0);

        unordered_map<char, int> mp;
        mp['R'] = 0;
        mp['B'] = 1;
        mp['W'] = 2;

        for (auto& k : edges) {
            int i = k[0];
            int j = k[1];

            degree[i]++;
            degree[j]++;

            if (mp[colors[i]] == mp[colors[j]])
                continue;

            if ((mp[colors[i]] + 1) % 3 == mp[colors[j]])
                indegree[j]++;
            else
                indegree[i]++;
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1)
                    return -1;
                root = i;
            }
        }

        if (root != -1 && degree[root] <= 2)
            return root;

        return -1;
    }
};