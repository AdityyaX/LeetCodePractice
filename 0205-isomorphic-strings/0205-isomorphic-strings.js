/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {
    if (s.length != t.length) return false
    const a = new Array(256).fill(0)
    const b = new Array(256).fill(0)
    for (let i = 0; i < s.length; i++) {
        if (a[s[i]] !== b[t[i]]) return false

        a[s[i]] = i + 1
        b[t[i]] = i + 1
    }
    return true

};