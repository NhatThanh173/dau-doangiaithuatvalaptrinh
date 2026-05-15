class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int tongTatCa = 0;

        for(int i = 0; i < nums.size(); i++){
            tongTatCa += nums[i];
        }

        int tongBenTrai = 0;

        for(int i = 0; i < nums.size(); i++){

            int tongBenPhai = tongTatCa - tongBenTrai - nums[i];

            if(tongBenTrai == tongBenPhai){
                return i;
            }

            tongBenTrai += nums[i];
        }

        return -1;
    }
};