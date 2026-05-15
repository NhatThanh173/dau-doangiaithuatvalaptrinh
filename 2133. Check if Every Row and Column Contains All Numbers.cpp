class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // check rows
        for(int i = 0; i < n; i++){
            vector<bool> seen(n+1,false);
            for(int j = 0; j < n; j++){
                int num = matrix[i][j];
                if(seen[num]) return false;
                seen[num] = true;
            }
        }

        // check columns
        for(int j = 0; j < n; j++){
            vector<bool> seen(n+1,false);
            for(int i = 0; i < n; i++){
                int num = matrix[i][j];
                if(seen[num]) return false;
                seen[num] = true;
            }
        }

        return true;
    }
};