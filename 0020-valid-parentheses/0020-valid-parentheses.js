/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    const stack = []
    const map = {
        ')': '(',
        '}': '{',
        ']': '['
    };
    for (const ch of s) {
        if (ch == '{' || ch == '(' || ch == '[') {
            stack.push(ch);
        } else {
            if (stack.length === 0) return false;
            const top = stack.pop();

            if (top !== map[ch]) {
                return false;
            }


        }
    }
    return stack.length === 0;

};