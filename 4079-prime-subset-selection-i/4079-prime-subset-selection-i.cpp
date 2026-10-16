class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;

        if (n < 2 || s < 2) return ans;

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; 1LL * i * i <= n; i++) {
            if (isPrime[i]) {
                for (long long j = 1LL * i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        long long sum = 0;

        for (int i = 2; i <= n; i++) {
            if (!isPrime[i]) continue;

            if (sum + i > s) break;

            ans.push_back(i);
            sum += i;
        }

        return ans;
    }
};