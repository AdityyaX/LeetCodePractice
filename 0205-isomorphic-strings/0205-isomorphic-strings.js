/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {
    const mapST = new Map();
    const mapTS = new Map();

    for (let i = 0; i < s.length; i++) {
        const ch1 = s[i];
        const ch2 = t[i];

        if (mapST.has(ch1) && mapST.get(ch1) !== ch2) {
            return false;
        }

        if (mapTS.has(ch2) && mapTS.get(ch2) !== ch1) {
            return false;
        }

        mapST.set(ch1, ch2);
        mapTS.set(ch2, ch1);
    }

    return true;
};