class Solution {
    void f(int k ,int n,  set<vector<int>>&op,vector<int>&temp, vector<int>&ans,int i){
        if(i>ans.size()|| n < 0 || temp.size() > k)return ;
        if(n==0 && temp.size()==k){
            op.insert(temp);
            return;
        }
        temp.push_back(ans[i]);
        f(k,n-ans[i],op,temp,ans,i+1);
        temp.pop_back();
         f(k,n,op,temp,ans,i+1);
         return ;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            ans.push_back(i);
        }
       set<vector<int>>op;
        vector<int>temp;
        f(k,n,op,temp,ans,0);
        vector<vector<int>>t;
        for(auto k:op)t.push_back(k);
        return t;
    }

};