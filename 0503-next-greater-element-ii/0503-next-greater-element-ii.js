var nextGreaterElements = function(nums) {
    let arr = [...nums];

    for (let i = 0; i < nums.length; i++) {
        arr.push(nums[i]);
    }

    let stack = [];
    let ans = [];
    let n = arr.length;

    for (let i = n - 1; i >= 0; i--) {
        while (
            stack.length > 0 &&
            stack[stack.length - 1] <= arr[i]
        ) {
            stack.pop();
        }

        if (stack.length === 0)
            ans.push(-1);
        else
            ans.push(stack[stack.length - 1]);

        stack.push(arr[i]);
    }

    ans.reverse();

    return ans.slice(0, nums.length);
};