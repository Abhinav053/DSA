class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = nums.front(); i <= nums.back(); i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
