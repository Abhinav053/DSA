class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
       int i=0;
       int j=nums.size()-1;
       while(i<j){
        int mid=(i+j)/2;
       // if(nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1])return mid;
        if(nums[mid]<nums[mid+1]){
            i=mid+1;
        }
        else j=mid;
       } 
       return i;
    }
};