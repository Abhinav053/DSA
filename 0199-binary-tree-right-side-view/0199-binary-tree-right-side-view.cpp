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
    vector<int>layer;
    vector<int>ans;
    void f(TreeNode* root,int n){
        if(root==NULL){
            return;
        }
        if(layer[n]==0)ans.push_back(root->val);
        layer[n]=1;


        if(root->right){
            f(root->right,n+1);
        }
        if(root->left){
            f(root->left,n+1);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        layer.resize(100,0);
         f(root,0);
         return ans;
    }
};