/**
 * @param {number[]} nums
 * @return {number}
 */
 let dp=[];
let f = function (nums, i) {
    if (i >= nums.length) return 0;
    if(dp[i]!=-1)return dp[i];
   
    let pick = -1e9;
    let notpick = -1e9;
    
        pick = nums[i] + f(nums, i + 2);
    
    notpick = f(nums, i + 1);
    return dp[i]= Math.max(pick, notpick)
}
var rob = function (nums) {
    for(let i=0;i<=nums.length;i++)dp[i]=-1;
    return f(nums, 0);
};