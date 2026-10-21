class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=m-1;

        while(i<=j){
            int mid=(i+j)/2;
             
             if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                int k=0;
                int l=n-1;
                while(k<=l){
                    int m=(k+l)/2;
                    if(matrix[mid][m]==target)return true;
                    if(matrix[mid][m]>target)l=m-1;
                    else k=m+1;
                }
             }


             if(matrix[mid][0]>target){
                j=mid-1;
             }
             else i=mid+1;
        }
        return false;

    }
};