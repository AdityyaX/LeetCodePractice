/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var shortestBeautifulSubstring = function(s, k) {
    let ans = "";
    let minLength = Infinity;
    let onesCount = 0;
    let left = 0;
    for (let right = 0; right < s.length; right++) {
        if (s[right] === '1') {
            onesCount++;
        }

        while (onesCount === k) {
            let currentLength = right - left + 1;
            let currentStr = s.substring(left, right + 1);
            if (currentLength < minLength) {
                minLength = currentLength;
                ans = currentStr;
            } else if (currentLength === minLength) {
                if (currentStr < ans) {
                    ans = currentStr;
                }
            }

            if (s[left] === '1') {
                onesCount--;
            }
            left++;
        }
    }

    return ans;
};
