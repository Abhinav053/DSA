class Solution {
    void f(vector<string>& arr, vector<string>& ans,
           string& temp, int i, int j) {

        if (i == arr.size()) {
            ans.push_back(temp);
            return;
        }

        if (j >= arr[i].size())
            return;

        // Pick arr[i][j]
        temp.push_back(arr[i][j]);
        f(arr, ans, temp, i + 1, 0);   
        temp.pop_back();

       
        f(arr, ans, temp, i, j + 1);
    }

public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        string mp[8] = {
            "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> arr;

        for (char ch : digits)
            arr.push_back(mp[ch - '2']);

        vector<string> ans;
        string temp;

        f(arr, ans, temp, 0, 0);

        return ans;
    }
};