class Solution {
    long long f(vector<int>& piles, int mid){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
           
            ans+=(piles[i]+mid-1)/mid;
          

        }
       
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(f(piles,mid)<=h){
                j=mid-1;
                ans=mid;
            }
            else i=mid+1;
        }
        return ans;
    }
};