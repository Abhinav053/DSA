class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        // set<int>evn,odd;
        // for(int i=0;i<n;i++){
        //     if(nums1[i]%2==0)evn.insert(nums1[i]);
        //     else odd.insert(nums1[i]);
        // }

        sort(nums1.begin(),nums1.end());
      
        if(nums1[0]%2==0){
            int odd=0;
            for(int i=0;i<n;i++){
                if(nums1[i]%2!=0){
                    if(odd<1)return false;
                }
                if(nums1[i]%2==0)continue;
                else {
                    odd++;
                }

            }
        }
        return true;
    
    }
};


