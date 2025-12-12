/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
    let i = 0, j = s.length - 1;
    function isAlphaNum(c) {
        return /^[a-z0-9]$/i.test(c);
    }
    while (i < j) {

        while (i < j && !isAlphaNum(s[i])) i++;
        while (i < j && !isAlphaNum(s[j])) j--;

        if (s[i].toLowerCase() !== s[j].toLowerCase()) {
            return false;
        }

        i++;
        j--;
    }

    return true;
};