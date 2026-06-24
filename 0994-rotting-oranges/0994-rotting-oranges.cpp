class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        
        int time=0;
        int dx[4] = {-1, 0, 1, 0}; 
        int dy[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto[d,node]=q.front();
            int x=node.first;
            int y=node.second;
            q.pop();
            time=d;
            for(int i=0;i<4;i++){
                int n_x=dx[i]+x;
                int n_y=dy[i]+y;
                if(n_x>=m ||  n_x<0 || n_y>=n || n_y<0)continue;
                if(!vis[n_x][n_y] && grid[n_x][n_y]==1){
                    vis[n_x][n_y]=1;
                    q.push({d+1,{n_x,n_y}});
                }


            }
        }
           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                   return -1;
                }
            }
        }
        return time;
    }
};