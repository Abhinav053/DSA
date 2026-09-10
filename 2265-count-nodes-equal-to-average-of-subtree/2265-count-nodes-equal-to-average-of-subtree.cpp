class Solution {
    int count;

    vector<int> f(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        vector<int> left = f(root->left);
        vector<int> right = f(root->right);

        int sum = root->val + left[0] + right[0];
        int nodes = left[1] + right[1] + 1;

        int average = sum / nodes;

        if (average == root->val) {
            count++;
        }

        return {sum, nodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        f(root);
        return count;
    }
};