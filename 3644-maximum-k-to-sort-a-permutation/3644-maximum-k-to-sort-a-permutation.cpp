class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i])ans.push_back(nums[i]);
        }

        if(ans.size()<1)return 0;

        int nd =0;
        bool flag=false;
        for(int i=0;i<ans.size();i++){
            if(!flag){
                nd=ans[i];
                flag=true;
            }
            else nd=nd &ans[i];
        }
        
        return nd;
    }
};