class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        bool even=true;
        bool odd=true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0)continue;
            bool flag=false;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(abs(nums1[j]-nums1[i])%2==0){
                        flag=true;
                    }
                }
            }
            if(!flag)even=false;
        }
         for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0)continue;
            bool flag=false;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(abs(nums1[j]-nums1[i])%2!=0){
                        flag=true;
                    }
                }
            }
            if(!flag)odd=false;
        }
        if(odd || even)return true;
        return false;
    }
};