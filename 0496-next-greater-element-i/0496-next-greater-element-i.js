/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    let stack = [];
    let ans = [];

    let n = nums2.length;

    for (let i = n - 1; i >= 0; i--) {

        while (stack.length > 0 && stack[stack.length - 1] <= nums2[i]) {
            stack.pop();
        }

        if (stack.length === 0) {
            ans.push(-1);
        } else {
            ans.push(stack[stack.length - 1]);
        }

        stack.push(nums2[i]);
    }

   
    ans.reverse();

    let result = [];

    for (let i = 0; i < nums1.length; i++) {
        let idx = nums2.indexOf(nums1[i]);
        result.push(ans[idx]);
    }

    return result;
};