class Solution {
    bool f(int i,int x){
        int sum=0;
        while(x>0){
            sum+=(x%10);
            x=x/10;

        }
        return (sum==i);
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(f(i,nums[i])){
                return i;
            }
        }
        return -1;
    }
};