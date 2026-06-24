class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        using t=pair<int,pair<int,int>>;
        priority_queue<t,vector<t>,greater<t>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int mini=1e9;
        int dx[4] = {-1, 0, 1, 0}; // up, right, down, left
int dy[4] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [cost,node]=q.top();
            int x=node.first;
            int y=node.second;
            if(x==m-1 && y==n-1){
                mini=min(mini,cost);
            }
            q.pop();
            for(int i=0;i<4;i++){
                int n_x=dx[i]+x;
                int n_y=dy[i]+y;
                if(n_x>=m || n_x<0 || n_y>=n || n_y<0)continue;
                if(!vis[n_x][n_y]){
                    int k=max(cost,grid[n_x][n_y]);
                    q.push({k,{n_x,n_y}});
                    vis[n_x][n_y]=1;
                }
            }
        }
        return mini;
    }
};