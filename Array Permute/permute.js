const factorial = function (num) {
    if (num < 0) {
        return;
    }
    if (num === 0) {
        return 1;
    }
    let ans = 1;
    for (let i = 1; i <= num; i++) {
        ans *= i;
    }
    return ans;
};
var permute = function (nums) {
    let res = [];
    let n = nums.length;
    let resSize = factorial(n);
    let slots, track, idToInsert;
    //Number of empty slots to put i-th element is factorial(i + 1)
    for (let i = 0; i < resSize; i++) {
        let firstEle = [nums[0]];
        res.push(firstEle);
    }
    for (let i = 1; i < n; i++) {
        slots = resSize / factorial(i + 1);
        track = -1;
        for (let j = 1; j <= factorial(i + 1); j++) {
            track = (track == i) ? track = 0 : track + 1;
            for (let k = 1; k <= slots; k++) {
                idToInsert = slots * (j - 1) + k - 1;
                let curArr = [];
                curArr = res[idToInsert];
                curArr.splice(track, 0, nums[i]);
            }
        }
    };
    console.log(res)
    return res;
};

permute([1,2,3,4])

