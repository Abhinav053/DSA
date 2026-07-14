class Solution {
    void f(vector<int>& nums,int i ,set<vector<int>>&ans,vector<int>&temp){
        if(i==nums.size()){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return ;
        }
        temp.push_back(nums[i]);
        f(nums,i+1,ans,temp);
        temp.pop_back();
        f(nums,i+1,ans,temp);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
         sort(nums.begin(),nums.end());
        f(nums,0,ans,temp);
        vector<vector<int>>t;
        for(auto k:ans)t.push_back(k);
        return t;
    }
};