class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int viTri1 = 0; viTri1 < nums.size(); viTri1++) {
            for (int viTri2 = viTri1 + 1; viTri2 < nums.size(); viTri2++) {
                if (nums[viTri1] + nums[viTri2] == target) {
                    return {viTri1, viTri2};
                }
            }
        }
        return {};
    }
};
