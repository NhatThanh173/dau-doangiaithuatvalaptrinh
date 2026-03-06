class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int demHienTai = 0;
        int maxLienTiep = 0;

        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == 1){
                demHienTai++;
                
                if(demHienTai > maxLienTiep){
                    maxLienTiep = demHienTai;
                }
            }
            else{
                demHienTai = 0;
            }

        }

        return maxLienTiep;
    }
};