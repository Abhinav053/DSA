class Solution {
    bool f(vector<int>& bloomDay, int m, int k,int mid){
        int ans=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else {
                ans+=count/k;
                count=0;
            }
        }

        if(count>0)ans+=count/k;
        return ans>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size())return -1;
        int i=*min_element(bloomDay.begin(),bloomDay.end());
        int j=*max_element(bloomDay.begin(),bloomDay.end());

        while(i<j){
            int mid=(i+j)/2;
            if(f(bloomDay,m,k,mid)){
                j=mid;
            }
            else i=mid+1;
        }
        return i;
    }
};