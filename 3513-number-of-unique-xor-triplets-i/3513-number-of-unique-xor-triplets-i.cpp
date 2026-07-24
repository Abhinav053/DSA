class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
         int n = nums.size();
        
      
        if (n == 1 || n == 2) {
            return n;
        }
        
      
        int res=32-__builtin_clz(n);
        
        return pow(2,res);
    }
};