class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<long long, long long> mp;
        mp[0] = 1;

        long long curr = 0;
        long long vp = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                vp += mp[curr];
                curr++;
            } else {
                curr--;
                vp -= mp[curr];
            }

            mp[curr]++;
            ans += vp;
        }

        return ans;
    }
};