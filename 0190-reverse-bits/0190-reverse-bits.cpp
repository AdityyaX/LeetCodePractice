class Solution {
public:
    // logic for this is simple just
    // first lets make space in end of result with 0
    // replace that zero with last digit of n
    // move n to right side by right side operator
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        return result;
    }
};