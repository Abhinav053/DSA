class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    
        sort(arr.begin(),arr.end());
        if(arr[0]!=1)arr[0]=1;
        if(arr.size()==1)return 1;
        int maxi=0;
        for(int i=1;i<arr.size();i++){
         
            if(arr[i]-arr[i-1]>1) {
                arr[i]=arr[i-1]+1;
            }

            maxi=max(maxi,arr[i]);
        }
        return maxi;

    }
};




// 1,2,2,2,6,1
// 1,1,2,2,2,6,6,9,12
// if(a[i]-a[i-1]<=1)conitnue;;
// else {
//     a[i]=a[i-1]+1;

// }
// maxi=max(maxi,a[i]);