class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);

        int give = 1;
        int i = 0;

        while(candies > 0) {
            int person = i % num_people;

            int cur = min(give, candies);
            res[person] += cur;

            candies -= cur;
            give++;
            i++;
        }

        return res;
    }
};