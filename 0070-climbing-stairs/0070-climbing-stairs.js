/**
 * @param {number} n
 * @return {number}
 */
let dp=[];
 let f=function(n){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1)+f(n-2);
 }
var climbStairs = function(n) {
    for(let i=0;i<=n;i++)dp[i]=-1;
    return f(n);
};