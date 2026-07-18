class Solution {
    unordered_map<string, int> mp;

    bool valid(const string &s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            if (++freq[c - 'a'] > 1)
                return false;
        }
        return true;
    }

    int f(vector<string>& arr, int i, string str) {
        if (!valid(str))
            return -1000000000;

        if (i == arr.size())
            return str.size();

        string key = to_string(i) + "#" + str;
        if (mp.count(key))
            return mp[key];

        int take = f(arr, i + 1, str + arr[i]);
        int leave = f(arr, i + 1, str);

        return mp[key] = max(take, leave);
    }

public:
    int maxLength(vector<string>& arr) {
        mp.clear();
        return max(0, f(arr, 0, ""));
    }
};