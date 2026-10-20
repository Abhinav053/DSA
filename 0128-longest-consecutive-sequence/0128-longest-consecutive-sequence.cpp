class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=0;
        unordered_set<int>st(nums.begin(),nums.end());

        for(auto k:st){
            if(st.find(k-1)==st.end()){
                int cnt=1;
                while(st.find(k+1)!=st.end()){
                    cnt++;
                    k=k+1;
                }
                maxi=max(maxi,cnt);
            }
        }
     
        return maxi;
    }
};