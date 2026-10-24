
class Solution {
    vector<vector<int>> ans;
    vector<int> temp;

    void f(vector<int>& c, int t, int i, int sum) {
        if (sum == t) {
            ans.push_back(temp);
            return;
        }

        if (i >= c.size() || sum > t) {
            return;
        }

        
        f(c, t, i + 1, sum);

       
        temp.push_back(c[i]);
        f(c, t, i, sum + c[i]);
        temp.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        f(c, t, 0, 0);
        return ans;
    }
};
