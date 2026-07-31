class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto& it:word){
            mp[it]++;
        }
        vector<int>v;
        for(auto& it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        int row=1;
        for(int i=0;i<v.size();i++){
            if(i>7 && i%8==0){
                row++;
            }
            ans=ans+v[i]*row;
        }
        return ans;
    }
};