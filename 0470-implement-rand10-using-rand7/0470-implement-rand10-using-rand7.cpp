// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
// in this what we are doing is
class Solution {
public:
    int rand10() {
        while (true) {
            int r1 = rand7();
            int r2 = rand7();
            int num = (r1 - 1) * 7 + r2;
            if (num <= 40)
                return (num - 1) % 10 + 1;
        }
    }
};