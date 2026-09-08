class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long maxi = 0;

        while (!q.empty()) {
            int n = q.size();

            // Index of first node in this level
            unsigned long long first = q.front().second;

            unsigned long long last = first;

            for (int j = 0; j < n; j++) {
                auto [node, idx] = q.front();
                q.pop();

                // Normalize index to avoid overflow
                idx = idx - first;

                last = idx;

                if (node->left) {
                    q.push({node->left, 2 * idx + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * idx + 2});
                }
            }

            maxi = max(maxi, last + 1);
        }

        return (int)maxi;
    }
};