class Solution {
  int dp[10001];
    bool f(vector<int>& nums,int i){
        if(i==nums.size()-1)return true;
        if(i>=nums.size())return false;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(f(nums,i+j))return dp[i]=true;
        }
        return dp[i]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0);
    }
};