class Solution {
    int m,n;
    vector<vector<int>>dp;
    int f(vector<vector<int>>& nums,int i,int j){
        if(i==m-1 && j==n-1 && nums[i][j]!=1 )return 1;
        
        if(i>=m || j>=n)return 0;
        if(nums[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=f(nums,i,j+1);
        int left=f(nums,i+1,j);
        return dp[i][j]=right+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        m=nums.size();
        n=nums[0].size();
        dp.assign(m,vector<int>(n,-1));
        return f(nums,0,0);
    }
};