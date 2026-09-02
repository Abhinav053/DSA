class Solution {
    map<int,vector<pair<int,int>>>mp;

    void f(TreeNode* root,int x,int y){
        if(root==NULL)return;

        mp[y].push_back({root->val,x});

        if(root->left){
            f(root->left,x+1,y-1);
        }

        if(root->right){
            f(root->right,x+1,y+1);
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        f(root,0,0);

        for(auto &k:mp){

            sort(k.second.begin(),k.second.end(),
                [&](pair<int,int>&a,pair<int,int>&b){
                    if(a.second==b.second)
                        return a.first<b.first;

                    return a.second<b.second;
                }
            );

            vector<int>temp;

            for(auto p:k.second){
                temp.push_back(p.first);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};