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
    int f(TreeNode* root,int& k){
        if(root==NULL)return 0;
        int left=0;
        int right=0;
        if(root->left){
            left=1+f(root->left,k);
        }
        if(root->right){
            right=1+f(root->right,k);
        }
        k=max(k,abs(left-right));
        return max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int k=0;
        int p=f(root,k);
        if(k>1)return false;
        return true;
    }
};