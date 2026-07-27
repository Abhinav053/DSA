class Solution {
     int dp[10001];
    int f(vector<int>& nums,int i){
        if(i==nums.size()-1)return 0;
        if(i>=nums.size())return 1e9;
        if(dp[i]!=-1)return dp[i];
        int ans=1e9;
        for(int j=1;j<=nums[i];j++){
            ans=min(ans,1+f(nums,i+j));
        }
        return dp[i]=ans;
    }
public:
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0); 
    }
};