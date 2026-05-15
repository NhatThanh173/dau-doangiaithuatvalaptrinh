class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> a, b;

        // nums1 - nums2
        for(int x : set1)
        {
            if(set2.find(x) == set2.end())
                a.push_back(x);
        }

        // nums2 - nums1
        for(int x : set2)
        {
            if(set1.find(x) == set1.end())
                b.push_back(x);
        }

        return {a, b};
    }
};