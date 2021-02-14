/**
 * @param {string} s
 * @return {number}
 */
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000


let res = 0;
var romanToInt = function (s) {
    let arr = s.split('');
    res += checkMinusInRoman(arr, 'M', 'C', 1000, 100);
    console.log(res);
    res += checkMinusInRoman(arr, 'D', 'C', 500, 100);
    console.log(res);
    res += checkMinusInRoman(arr, 'C', 'X', 100, 10);
    console.log(res);
    res += checkMinusInRoman(arr, 'L', 'X', 50, 10);
    console.log(res);
    res += checkMinusInRoman(arr, 'X', 'I', 10, 1);
    console.log(res);
    res += checkMinusInRoman(arr, 'V', 'I', 5, 1);
    console.log(res);
    res += arr.length;
    console.log(res);
    return res;
};
function checkMinusInRoman(arr, letter, preLetter, letterValue, preLetterValue) {
    let id, res = 0;
    while (arr.indexOf(`${letter}`) !== -1) {
        id = arr.indexOf(`${letter}`);
        if (id > 0 && arr[id - 1] == `${preLetter}`) {
            res += (letterValue - preLetterValue);
            arr.splice(id - 1, 2);
        } else {
            res += letterValue;
            arr.splice(id, 1);
        }
        console.log(arr.length);
    }
    return res;
}
romanToInt('IV')
