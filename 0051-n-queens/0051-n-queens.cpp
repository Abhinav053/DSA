class Solution {
    bool safe(int n,vector<string>&op,int i,int j){
        for(int row=0;row<n;row++){
            if(op[row][j]=='Q')return false;
        }

        for(int p=i-1,k=j-1 ;p>=0&&k>=0 ;p--,k--){
            if(op[p][k]=='Q')return false;
        }

         for(int p=i-1,k=j+1 ;p>=0&&k<n ;p--,k++){
            if(op[p][k]=='Q')return false;
        }
        return true;
    }
    void f(int n, vector<vector<string>>&ans, vector<string>&op,int i){
        if(i>=n){
            ans.push_back(op);
            return ;
        }

        for(int col=0;col<n;col++){
            if(safe(n,op,i,col)){
            op[i][col]='Q';
            f(n,ans,op,i+1);
            op[i][col]='.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>op(n,string(n,'.'));
        f(n,ans,op,0);
        return ans;
    }
};