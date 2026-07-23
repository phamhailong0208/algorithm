class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid; // tìm thấy
            } else if (nums[mid] < target) {
                left = mid + 1; // tìm bên phải
            } else {
                right = mid - 1; // tìm bên trái
            }
        }
        return left; // không tìm thấy, vị trí chèn là left
    }
};