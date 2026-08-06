/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val === undefined ? null : val;
 *    this.children = children === undefined ? null : children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number}
 */
var maxDepth = function (root) {
    if (root === null) return 0;

    let max = 0
    for (const childern of root.children) {
        max = Math.max(maxDepth(childern), max)

    }
    return max + 1
};