class Solution {
public:
    int findPeakElement(vector<int>& nums) {
     int i=0;
     int j=nums.size()-1;
      if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;

     while(i<j){
        int mid=(i+j)/2;
        if(nums[mid]<nums[mid+1]){
            i=mid+1;
        }
        else j=mid;
     }
     return i;
    }
};