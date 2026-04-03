class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {

        int freq[1001] = {0};

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == key)
            {
                int target = nums[i+1];
                freq[target]++;
            }
        }

        int ans = 0;
        int maxCount = 0;

        for(int i = 0; i <= 1000; i++)
        {
            if(freq[i] > maxCount)
            {
                maxCount = freq[i];
                ans = i;
            }
        }

        return ans;
    }
};