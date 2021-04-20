/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    if (nums.length < 3 || !nums) {
        return [];
    }
    let res = [];
    let i, start, end, sum, n = nums.length;
    nums.sort((a, b) => a - b);
    for (i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        start = i + 1;
        end = n - 1;
        if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
            break;
        }
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if (sum > 0) {
                end--;
            }
            else if (sum < 0) {
                start++;
            }
            else {
                let triplet = [];
                triplet.push(nums[i], nums[start], nums[end]);
                res.push(triplet);
                while (nums[start] == nums[start + 1]) {
                    start++;
                }
                while (nums[end] == nums[end - 1]) {
                    end--;
                }
                end--;
                start++;
            }
        }
    }
    console.log(res);
    return res;
};

threeSum([77, -33, -44, 205, -105, -100, 55, -55, 0, 1, -1, 2, -2, 3, -3, 1]);