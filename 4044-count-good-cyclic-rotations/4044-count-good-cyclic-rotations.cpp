class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int n = nums.size();

        
        for (int i = 0; i < n / 2; i++) {
            nums.push_back(nums[i]);
        }

        long long sum = accumulate(nums.begin(), nums.begin() + n, 0LL);

        long long  first = 0;
        int j = 0;

        
        for (int i = 0; i < n / 2; i++) {
            first += nums[i];
            j++;
        }

        int i = 0;
        int count = 0;

        while (i < n) {

            if (first > sum - first)
                count++;

        
            first -= nums[i];

            first += nums[j];

            i++;
            j++;
        }

        return count;
    }
};