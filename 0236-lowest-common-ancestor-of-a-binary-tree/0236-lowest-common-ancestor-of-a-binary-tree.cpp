class Solution {
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        TreeNode* left = NULL;
        TreeNode* right = NULL;

        if(root->left){
            left = f(root->left,p,q);
        }

        if(root->right){
            right = f(root->right,p,q);
        }

        if(left && right)
            return root;

        if(left)
            return left;

        if(right)
            return right;

        return NULL;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};