class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int>q;
        for(auto p:nums){
            q.push(p);
        }
        long long sum=0;
        while(!q.empty() && k>0){
            int a=q.top();
            q.pop();
            if(mul>0){
                sum+=1LL*a*mul;
                mul--;
            }
            else sum+=a;
            k--;
        }
        return sum;
    }
};