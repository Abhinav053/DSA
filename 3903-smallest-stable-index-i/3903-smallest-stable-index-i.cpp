class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> maxi(n), mini(n);

       
        int maxx = nums[0];
        maxi[0] = nums[0];
        for(int i = 1; i < n; i++){
            maxx = max(maxx, nums[i]);
            maxi[i] = maxx;
        }

       
        int minn = nums[n-1];
        mini[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            minn = min(minn, nums[i]);
            mini[i] = minn;
        }

        for(int i = 0; i < n; i++){
            if(abs(maxi[i] - mini[i]) <= k){
                return i;
            }
        }

        return -1;
    }
};