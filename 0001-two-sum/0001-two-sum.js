var twoSum = function(nums, target) {

    let arr = [];

    for (let i = 0; i < nums.length; i++) {
        arr.push({
            value: nums[i],
            index: i
        });
    }

    arr.sort((a, b) => a.value - b.value);

    let i = 0;
    let j = arr.length - 1;

    while (i < j) {

        let sum = arr[i].value + arr[j].value;

        if (sum === target) {
            return [arr[i].index, arr[j].index];
        }

        if (sum < target)
            i++;
        else
            j--;
    }

    return [];
};