class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);

        for (int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];

            outDegree[a]++;
            inDegree[b]++;
        }

        for (int person = 1; person <= n; person++) {
            if (inDegree[person] == n - 1 && outDegree[person] == 0) {
                return person;
            }
        }

        return -1;
    }
};

