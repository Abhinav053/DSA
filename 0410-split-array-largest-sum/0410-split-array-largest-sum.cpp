class Solution {
    bool f(vector<int>& nums, int k,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            
            if(sum + nums[i] <= mid){
                sum+=nums[i];
            }
            else {
                k--;
                sum=nums[i];
            }
            if(k<=0)return false;
        }
      
       return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
      int i = *max_element(nums.begin(), nums.end());
       int j = accumulate(nums.begin(), nums.end(), 0);
       int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(f(nums,k,mid)){
                j=mid-1;
                ans=mid;
            }
            else i=mid+1;
        }
        return i;
    }
};