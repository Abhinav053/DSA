class Solution {
public:
    int t[51];

    int solve(int i, string& s, unordered_set<string>& st, int& n) {
        if (i >= n) return 0;

        if (t[i] != -1) return t[i];

        string str = "";
        int total = n;

        for (int j = i; j < n; j++) {
            str.push_back(s[j]);

            int extra = j - i + 1;

            if (st.count(str)) {
                extra = 0;
            }

            int ans = extra + solve(j + 1, s, st, n);

            total = min(total, ans);
        }

        return t[i] = total;
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();

        memset(t, -1, sizeof(t));

        unordered_set<string> st(begin(dict), end(dict));

        return solve(0, s, st, n);
    }
};