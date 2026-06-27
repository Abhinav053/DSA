class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi=0;
        for(auto k:st){
            if(st.find(k-1)==st.end()){
                int count=1;
                while(st.find(k+1)!=st.end()){
                    count++;
                    k=k+1;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};