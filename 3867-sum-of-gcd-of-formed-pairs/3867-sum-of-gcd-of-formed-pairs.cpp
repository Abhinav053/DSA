class Solution {
 int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
public:
    long long gcdSum(vector<int>& nums) {
       vector<int> maxi(nums.size());
int maxii=nums[0];
for (int i = 0; i < nums.size(); i++) {
    maxii = max(maxii, nums[i]);
    maxi[i] = maxii;
}

 vector<int>p_gcd;
        for(int i=0;i<nums.size();i++){
        int k=gcd(maxi[i],nums[i]);
        p_gcd.push_back(k);
        }
        sort(p_gcd.begin(),p_gcd.end());

        int i=0;
        int j=p_gcd.size()-1;
        long long sum=0;
        while(i<j){
            sum+=1LL*(gcd(p_gcd[j],p_gcd[i]));
            i++;
            j--;
        }
        return sum;
    }
};