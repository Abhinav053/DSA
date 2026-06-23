class Solution {
    int m,n;
    vector<vector<int>>vis;
    void dfs(vector<vector<int>>& grid,int i,int j,int &count){
        if(i>=m|| i<0 || j>=n || j<0)return ;
        vis[i][j]=1;
        count++;
         int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for(int k=0;k<4;k++){
            int n_x=i+dx[k];
            int n_y=j+dy[k];
            if(n_x>=m || n_x<0 || n_y>=n || n_y<0)continue;
            if(!vis[n_x][n_y] && grid[n_x][n_y]==1){
                dfs(grid,n_x,n_y,count);
            }
        }
        return ;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
         vis.assign(m,vector<int>(n,0));
         int maxi=-1e9;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int count=0;
                    dfs(grid,i,j,count);
                    //cout<<count<<" ";
                    maxi=max(maxi,count);
                }
            }
        }
        if(maxi==-1e9)return 0;
        return maxi;
    }
};