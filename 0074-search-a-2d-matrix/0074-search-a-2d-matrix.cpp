class Solution {
    bool f(vector<vector<int>>& mat,int i,int j ,int mid,int t){
        while(i<=j){
            int p=(i+j)/2;
            if(mat[mid][p]==t)return true;
            if(mat[mid][p]>t)j=p-1;
            else i=p+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m=mat.size();
        int n=mat[0].size();
        int i=0;
        int j=m-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(mat[mid][0]<=t && mat[mid][n-1]>=t){
               
                return f(mat,0,n-1,mid,t);
            }
            else if(mat[mid][0]>t){
                j=mid-1;
            }
            else i=mid+1;
        }
        return false;
    }
};