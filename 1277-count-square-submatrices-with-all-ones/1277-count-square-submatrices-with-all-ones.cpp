class Solution {
    int m,n;
    vector<vector<int>>dp;
    int f(vector<vector<int>>& mm,int i,int j){
         if(i>=m || i<0 || j>=n ||j<0)return 0;
        if(mm[i][j]==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
       
         
         int left=1+f(mm,i,j+1);
        int down=1+f(mm,i+1,j);
        int d=1+f(mm,i+1,j+1);
        return dp[i][j]=min({left,down,d});
    }
public:
    int countSquares(vector<vector<int>>& mm) {
        m=mm.size();
        n=mm[0].size();
        dp.assign(m,vector<int>(n,-1));
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mm[i][j]==1){
                    cout<<i<< " "<<j;
                    sum+=f(mm,i,j);
                }
            }
        }
        return sum;
    }
};

