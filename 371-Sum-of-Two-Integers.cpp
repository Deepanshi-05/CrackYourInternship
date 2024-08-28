class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1; // Calculate the carry
            a = a ^ b;                // Calculate the sum without carry
            b = carry;
        }
        return a;
    }
};