class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);

            if (res == 0) {
                return mid;
            }
            else if (res == -1) {
                right = mid - 1; // đoán lớn → qua trái
            }
            else {
                left = mid + 1;  // đoán nhỏ → qua phải
            }
        }

        return -1; // không cần thiết nhưng để cho đủ
    }
};