class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>ans;
        for(auto k:nums){
            if(k!=0)ans.push_back(k);
        }
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;j--;
            }
            else if(nums[i]!=0 && nums[j]!=0){
                i++;
            }
            else if(nums[i]==0 && nums[j]==0){
                j--;
            }
            else {
                i++;
                j--;
            }
        }
         for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }

        for(int i=0;i<ans.size();i++){
            nums[i]=ans[i];
        }

    }
};