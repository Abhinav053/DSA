/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int f(TreeNode* root,int k){
        if(root==nullptr)return 0;
        int left=0;
        int right=0;
        if(root->left){
            if(root->left->val>=k){
                left=1+f(root->left,root->left->val);
            }
            else  left=f(root->left,k);
        }
           if(root->right){
            if(root->right->val>=k){
                right=1+f(root->right,root->right->val);
            }
            else  right=f(root->right,k);
        }
        return left+right;
    }
public:
    int goodNodes(TreeNode* root) {
        return 1+ f(root,root->val);
    }
};