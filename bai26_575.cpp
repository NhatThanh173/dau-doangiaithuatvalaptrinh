#include <unordered_set>

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set<int> tapLoaiKeo;

        for(int i = 0; i < candyType.size(); i++){
            tapLoaiKeo.insert(candyType[i]);
        }

        int soLoaiKeo = tapLoaiKeo.size();
        int soKeoDuocAn = candyType.size() / 2;

        if(soLoaiKeo < soKeoDuocAn){
            return soLoaiKeo;
        }
        else{
            return soKeoDuocAn;
        }
    }
};