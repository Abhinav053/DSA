class Solution {
    void f(int n,vector<int>&ans){
        while(n>0){
            ans.push_back(n%10);
            n=n/10;
        }
    }
public:
    bool checkDivisibility(int n) {
        vector<int>ans;
        f(n,ans);

int sum=0;
long long multi=1;
        for(auto k:ans)sum+=k;
        for(auto k:ans){
            multi=1LL*multi*k;
        }
        return (n%(sum+multi)==0);
    }
};