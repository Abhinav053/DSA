/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */

 function f(nums,mid,th){
    let sum=0;
    for(let i=0;i<nums.length;i++){
        sum+=Math.ceil(nums[i]/mid);
    }
    return sum<=th;
 }
var smallestDivisor = function(nums, th) {
    let i=1;
    let j=Math.max(...nums);
    while(i<j){
        let mid=Math.floor((i+j)/2);
        if(f(nums,mid,th)){
            j=mid;
        }
        else i=mid+1;
    }
    return j;
};
