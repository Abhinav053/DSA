class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3];
        for(auto k:nums){
            a[k]++;
        }
      //  vector<int>ans;
        int k=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<a[i];j++){
                nums[k]=i;
                k++;
            }
        }
        
    }
};