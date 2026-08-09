class Solution {
    int f(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;

        int take_i = nums[i] +
            min(
                f(nums, i + 2, j),
                f(nums, i + 1, j - 1)
            );

        int take_j = nums[j] +
            min(
                f(nums, i, j - 2),
                f(nums, i + 1, j - 1)
            );

        return max(take_i, take_j);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        int player1 = f(nums, 0, nums.size() - 1);

        int player2 = total - player1;

        return player1 >= player2;
    }
};