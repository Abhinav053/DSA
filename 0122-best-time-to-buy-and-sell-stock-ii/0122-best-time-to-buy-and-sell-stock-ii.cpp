class Solution {
    vector<vector<int>>dp;
    int f(vector<int>& p,int i,int canbuy){
        if(i>=p.size())return 0;
        if(dp[i][canbuy]!=-1)return dp[i][canbuy];
        int pick=-1e9;
        int not_pick=-1e9;
        if(canbuy){
            pick=-p[i]+f(p,i+1,0);
            not_pick=f(p,i+1,1);
        }
        else{
            pick=p[i]+f(p,i+1,1);
            not_pick=f(p,i+1,0);
        }
        return dp[i][canbuy]=max(pick,not_pick);
    }
public:
    int maxProfit(vector<int>& p) {
        dp.assign(p.size(),vector<int>(2,-1));
        return f(p,0,1);
    }
};