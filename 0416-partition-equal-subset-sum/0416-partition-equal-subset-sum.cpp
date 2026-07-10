class Solution {
    bool part(vector<int>& nums, int sum, int idx, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (idx < 0 || sum < 0) return false;

        if (dp[idx][sum] != -1) return dp[idx][sum];

        bool notpick = part(nums, sum, idx - 1, dp);
        bool pick = false;
        if (nums[idx] <= sum) {
            pick = part(nums, sum - nums[idx], idx - 1, dp);
        }

        return dp[idx][sum] = notpick || pick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return part(nums, target, nums.size() - 1, dp);
    }
};
