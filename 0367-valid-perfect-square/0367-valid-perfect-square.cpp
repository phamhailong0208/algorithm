class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return num;
        int left=2, right=num/2;
        while (left <= right) {
            long long mid = (left + right)/2;
            long long result = mid * mid ;
            if (result == num) return true;
            else if (mid * mid > num) {
                right = mid -1;
            }else {
                left = mid + 1;
            }
        }
        return false;
    }
};