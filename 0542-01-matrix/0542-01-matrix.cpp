class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
           int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int x[4] = {0, 1, 0, -1};
        int y[4] = {1, 0, -1, 0};
        while(!q.empty()){
            auto[a,b]=q.front();
            int l=a.first;
            int m=a.second;
            q.pop();
            for(int i=0;i<4;i++){
                int p=l+x[i];
                int k=m+y[i];

                if(p>=0 &&k>=0&& p<rows && k<cols && !vis[p][k]){
                    ans[p][k]=b+1;
                    vis[p][k]=1;
                    q.push({{p,k},b+1});
                }
            }
        }
        return ans;
    }
};