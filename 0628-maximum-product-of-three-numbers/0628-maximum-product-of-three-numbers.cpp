class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int k= nums[n-1]*nums[n-2]*nums[n-3];
        vector<int>neg;
        for(auto p:nums){
            if(p<0)neg.push_back(p);
        } 
       if(neg.size()>=2){
          sort(neg.begin(),neg.end());
         int l=neg[0]*neg[1]*nums[n-1];
         cout<<k<<l<<" ";
         return max(k,l);
       }
       return k;

    }
};