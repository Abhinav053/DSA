class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = 0;
        for (auto k : nums) {
            sum += k;
        }

        int t = sum - x;

        if (t < 0)
            return -1;

        if (t == 0)
            return n;

        int i = 0;
        int ans = 0;
        int maxi = -1;

        for (int j = 0; j < n; j++) {
            ans += nums[j];

            while (ans > t && i <= j) {
                ans -= nums[i];
                i++;
            }

            if (ans == t) {
                maxi = max(maxi, j - i + 1);
            }
        }

        if (maxi == -1)
            return -1;

        return n - maxi;
    }
};