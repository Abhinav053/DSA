class Solution {
    bool f(vector<int>& piles, int h, int m) {
        int count = 0;

        for (int i = 0; i < piles.size(); i++) {
            count += (piles[i] + m - 1) / m;

            if (count > h)
                return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = *max_element(piles.begin(), piles.end());

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (f(piles, h, mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }

        return i;
    }
};