class Solution {
public:
    int reverse(int x) {
        long long result = 0; // use long long to detect overflow

        while (x != 0) {
            int digit = x % 10;
            result = result * 10 + digit;
            x /= 10;

            // check overflow against 32-bit signed integer range
            if (result > INT_MAX || result < INT_MIN) {
                return 0;
            }
        }

        return (int)result;
    }
};