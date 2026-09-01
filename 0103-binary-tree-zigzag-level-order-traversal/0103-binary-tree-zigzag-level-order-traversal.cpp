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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
    return {};
        queue<TreeNode*>pq;
        pq.push(root);
        int layer=1;
        bool to_swap=true;
        vector<vector<int>>op;
        while(!pq.empty()){
            vector<int>ans;
            int n=pq.size();
            
            for(int i=0;i<n;i++){
                TreeNode* temp=pq.front();
                ans.push_back(temp->val);
                   
                if(temp->left){
                    pq.push(temp->left);
                   
                }
                if(temp->right){
                    pq.push(temp->right);
                    
                }
                pq.pop();
            }

            if(to_swap){
                op.push_back(ans);
            }
            else {
                reverse(ans.begin(),ans.end());
                op.push_back(ans);
            }

            to_swap=!to_swap;
         
        }
        return op;
    }
};