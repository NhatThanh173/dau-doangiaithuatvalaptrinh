class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ketQua;

        for(int i = 0; i < nums.size(); i++){
            int chiSo = abs(nums[i]) - 1;

            if(nums[chiSo] > 0){
                nums[chiSo] = -nums[chiSo];
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ketQua.push_back(i + 1);
            }
        }

        return ketQua;
    }
};