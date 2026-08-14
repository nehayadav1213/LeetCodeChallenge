class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes.
        // Numbers ending in 0 are not palindromes (except 0 itself).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;

        // Reverse only half of the digits.
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Even number of digits: x == reversed
        // Odd number of digits: ignore the middle digit using / 10
        return x == reversed || x == reversed / 10;
    }
};