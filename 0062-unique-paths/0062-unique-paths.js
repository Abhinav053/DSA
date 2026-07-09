/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
 let dp=[];
 let f=function (m,n,i,j){
    if(i>=m || i<0 || j>=n || j<0)return 0;
    if(i==m-1 && j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    let right= f(m,n,i,j+1);
    let down =f(m,n,i+1,j);
    return dp[i][j]= right+down;
 }
var uniquePaths = function(m, n) {
    dp = new Array(m).fill(0).map(() => new Array(n).fill(-1));
    return f(m,n,0,0);
};