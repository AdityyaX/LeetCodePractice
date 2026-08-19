/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */

// 1 x x 4 5 6 7 x 9 10
// 1 2 3 4 5 x 7 8 9 10
//  x 2 3 4 5 6 7 8 x x
var maxNumberOfFamilies = function (n, reservedSeats) {
    const map = new Map()
    for (let [row, reservedSeat] of reservedSeats) {
        if (!map.get(row)) {
            map.set(row, new Set())
        }
        map.get(row).add(reservedSeat);
    }
    let answer = 0;
    for (const [row, seats] of map) {
        const left = !seats.has(2) && !seats.has(3) && !seats.has(4) && !seats.has(5)

        const middle = !seats.has(4) && !seats.has(5) && !seats.has(6) && !seats.has(7)

        const right = !seats.has(6) && !seats.has(7) && !seats.has(8) && !seats.has(9)
        if (left && right) {
            answer += 2
        } else if (left || middle || right) {
            answer += 1
        }
    }
    answer += (n - map.size) * 2;
    return answer

};