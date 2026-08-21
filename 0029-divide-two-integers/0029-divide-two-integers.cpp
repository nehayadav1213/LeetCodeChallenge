class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case: INT_MIN / -1 = 2147483648
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long a = dividend;
        long long b = divisor;

        // Determine the sign of the answer
        bool negative = (a < 0) ^ (b < 0);

        // Work with positive values
        a = llabs(a);
        b = llabs(b);

        long long quotient = 0;

        // Find the largest multiples of divisor that fit
        while (a >= b) {
            long long value = b;
            long long multiple = 1;

            while (a >= value + value) {
                value += value;
                multiple += multiple;
            }

            a -= value;
            quotient += multiple;
        }

        if (negative) {
            quotient = -quotient;
        }

        // Clamp to 32-bit range
        if (quotient > INT_MAX) {
            return INT_MAX;
        }

        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return (int)quotient;
    }
};