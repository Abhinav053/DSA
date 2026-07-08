/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let maxi=0;
    let count=0;
    for(let i of nums){
        if(i==1)count++;
        else count=0;
        console.log(count);
        maxi=Math.max(maxi,count);
    }
    return maxi;
};