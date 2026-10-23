
class Solution {
    long long f(vector<int>& piles, int h) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + h - 1) / h;
        }

        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = *max_element(piles.begin(), piles.end());

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (f(piles, mid) <= h) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }

        return i;
    }
};
