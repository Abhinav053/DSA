class Solution {
    int m,n;
    vector<vector<int>>dp;
    int f(vector<vector<int>>& ob,int i,int j){
        if(i<0 || i>=m || j<0 ||j>=n)return 0;
        if(ob[i][j]==1)return 0;
        if(i==m-1&& j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        

        int right=f(ob,i,j+1);
        int down=f(ob,i+1,j);
        return dp[i][j]=right+down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return f(obstacleGrid,0,0);
    }
};