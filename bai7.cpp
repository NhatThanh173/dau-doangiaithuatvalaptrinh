class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        
        unordered_map<int, int> demTanSuat;
        for (int i = 0; i < nums.size(); i++) {
            demTanSuat[nums[i]]++;
        }

      
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto cap : demTanSuat) {
            int so = cap.first;
            int tanSuat = cap.second;
            bucket[tanSuat].push_back(so);
        }

 
        vector<int> ketQua;
        for (int tanSuat = nums.size(); tanSuat >= 0 && ketQua.size() < k; tanSuat--) {
            for (int so : bucket[tanSuat]) {
                ketQua.push_back(so);
                if (ketQua.size() == k) {
                    break;
                }
            }
        }

        return ketQua;
    }
};
