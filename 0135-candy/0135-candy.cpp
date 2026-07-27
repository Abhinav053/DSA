class Solution {
public:
    int candy(vector<int>& r) {
        vector<int>ans;
        for(int i=0;i<r.size();i++){
            ans.push_back(1);
        }
        for(int i=0;i<r.size()-1;i++){
            if(r[i+1]>r[i]){
                ans[i+1]=ans[i]+1;
            }
        }
        for(int i=r.size()-1;i>0;i--){
            if(r[i-1]>r[i]){
                if(ans[i-1]>ans[i])continue;
                ans[i-1]=ans[i]+1;
            }
        }

        for(auto p:ans)cout<<p<<" ";
        int k=accumulate(ans.begin(),ans.end(),0);
        return k;
    }
};