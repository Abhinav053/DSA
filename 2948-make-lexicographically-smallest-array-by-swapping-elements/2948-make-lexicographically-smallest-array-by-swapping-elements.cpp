class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> ans = nums;
        sort(ans.begin(), ans.end());

        unordered_map<int, list<int>> mp1;
        unordered_map<int, int> mp2;

        int idx = 0;

        
        for (int i = 0; i < ans.size(); i++) {

            if (i > 0 && abs(ans[i] - ans[i - 1]) > limit) {
                idx++;
            }

            mp1[idx].push_back(ans[i]);
            mp2[ans[i]] = idx;
        }

        vector<int> op;

       
        for (int i = 0; i < nums.size(); i++) {
            int k = nums[i];

            int grp = mp2[k];

            int mini = mp1[grp].front();
            mp1[grp].pop_front();

            op.push_back(mini);
        }

        return op;
    }
};